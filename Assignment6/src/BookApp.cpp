#include "Book.h"
#include <iostream>
#include <fstream>
#include <vector>

/***** Complete this file. *****/

using namespace std;

// Status codes.
enum class StatusCode {OK, DUPLICATE, NOT_FOUND, INVALID_COMMAND};

/**
 * Find the book in the catalog with the given ISBN.
 * Use a binary search.
 * @param isbn the ISBN.
 * @param catalog the vector of book records.
 * @return the vector index of the book if found, else return -1.
 */
int find(const string isbn,  vector<Book> &catalog);
void linearFind(const string searchTerm,const string value,  vector<Book> &catalog);

const string INPUT_FILE_NAME = "commands.in";

/**
 * The main. Open the command input file and loop to process commands.
 */
int main()
{
	// Open the input file.
	ifstream input;
	string wLine;
	string isbn,first,last,category="none",title,searchTerm="",value="";
	vector <vector<string>> records;
	int position;
	input.open(INPUT_FILE_NAME);
	if (input.fail())
	{
		cout << "Failed to open " << INPUT_FILE_NAME << endl;
		return -1;
	}



	string command;
	//input >> command;  // read the first command

	/**
	 * Loop to read commands until the end of file.
	 */
	//Read a Line, store the deilimted values in a line in a vector
	//i.e for a vector if vectors having values
	while (getline(input,wLine))
	{
		vector<string> line;
		//if no delimiter is present
		if(wLine.length()<2){
			line.push_back(wLine);
			records.push_back(line);
		}
		else{
			line.push_back(wLine.substr(0,1));
			wLine = wLine.substr(2);
			//parsing the data with , as delimiter
			while((position = wLine.find(','))>=0 ){
				string x = wLine.substr(0,position);
				wLine = wLine.substr(position+1);
				line.push_back(x);
			}
			//pasrsing data with = as delimiter
			while((position = wLine.find('='))>=0 ){
							string x = wLine.substr(0,position);
							wLine = wLine.substr(position+1);
							line.push_back(x);
						}
			line.push_back(wLine);
			records.push_back(line);
		}
	}
	vector<Book> catalog;  // book catalog
	//cout<<"catalog SIze"<<catalog.size()<<endl;
	for(int i=0;i<records.size();i++){
		command = records.at(i).at(0);

		cout << endl << command << " ";
		//case of adding a record
		if(command.compare("+")==0){

			isbn =records.at(i).at(1);
			last = records.at(i).at(2);
			first = records.at(i).at(3);
			title = records.at(i).at(4);
			category = records.at(i).at(5);
			//check if the ISBN aslready exists
			int exist = find(isbn, catalog);
			//cout<<"catalog SIze after find is"<<catalog.size()<<endl;
			int cSize = catalog.size();
			if(exist<0){
				Book b1(isbn,last,first,title,category);
				if(i==0){

					catalog.push_back(b1);
					cout<<"Inserted at index "<<i<<": ";
					cout<<catalog.at(0);

				}else{
					int j=0;
				for(j=0;j<cSize;j++){
					//cout<<"\ncatalog.size() = "<<catalog.size()<<endl;
					if(isbn.compare(catalog.at(j).getIsbn())<0){
						catalog.insert(catalog.begin()+j,b1);
						cout<<"Inserted at index "<<j<<": ";
						cout<<catalog.at(j);
						break;
					}
				}
				if(j==cSize){
					catalog.push_back(Book(isbn,last,first,title,category));
					cout<<"Inserted at index "<<j<<": "<<catalog.at(j);
				}
				}
			}else{
				cout<<"Inserted at index "<<exist<<": "<<catalog.at(exist);
				cout<<"*** Duplicate ISDN ***"<<endl;
			}
		}
		//querying a record
		else if(command.compare("?")==0){
			if(records.at(i).size()>1){
				searchTerm = records.at(i).at(1);
				value = records.at(i).at(2);
			}else{
				searchTerm="";
				value="";
			}

			linearFind(searchTerm,value,catalog);
		}else if(command.compare("-")==0){
			isbn = records.at(i).at(1);
			last = "";
			first = "";
			title = "";
			category = "none";
			int exist = find(isbn,catalog);
			if(exist>=0){
				cout<<" Removed "<<catalog.at(exist);
				catalog.erase(catalog.begin()+exist);
			}else{
				Book dumm(isbn,last,first,title, category);
				cout<<" Removed "<<dumm;
				cout<<"*** Book not found ***"<<endl;
			}
		}
		else{
			cout<<" *** Invalid command ***"<<endl;
		}
		/*** Complete this main. *****/
	}
	catalog.clear();
	return 0;
}

//binary search to find the book based on isbn
int find(const string isbn,  vector<Book> &catalog){
	int indexB = -1,mid=0,first = 0, last = catalog.size()-1;
	//cout<<"catalog size in find is"<<catalog.size()<<endl;
	if(last>0){
	while(first<=last){
		mid = (first+last)/2;
		if(isbn.compare(catalog.at(mid).getIsbn())==0){
			indexB = mid;
			break;
		}else if (isbn.compare(catalog.at(mid).getIsbn())<0){
			last = mid-1;
		}else{
			first = mid + 1;
		}

	}
	}
	return indexB;
}
//linear search for mutiple search
void linearFind(const string searchTerm,const string value,  vector<Book> &catalog){
	int indexF = -1;
	vector<int> indices;
	Book b;
	if(searchTerm.compare("isbn")==0){
		indexF = find(value, catalog);
		//indices.push_back(indexF);
		cout<<"Book with ISBN "<<value<<":"<<endl;
		if(indexF>=0)
			cout<<catalog.at(indexF);
	}

	if(searchTerm.compare("author")==0){
		cout<<"Books by "<<searchTerm<<" "<<value<<":"<<endl;
		for(int i =0; i<catalog.size();i++){
			b = catalog.at(i);
			if(value.compare(b.getLast())==0){
				cout<<catalog.at(i);
			}
		}
	}
	else if(searchTerm.compare("category")==0){
		cout<<"Books in "<<searchTerm<<" "<<value<<":"<<endl;
		for(int i =0; i<catalog.size();i++){
			if(value.compare(catalog.at(i).getCategory())==0){
				cout<<catalog.at(i);
			}
		}
	}
	else if(searchTerm.compare("")==0){
		cout<<"All books in the catalog:"<<endl;
		for(int i =0; i<catalog.size();i++){
			cout<<catalog.at(i);

		}
	}


}

