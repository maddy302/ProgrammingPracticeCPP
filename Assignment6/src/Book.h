#ifndef BOOK_H_
#define BOOK_H_

#include <string>
using namespace std;

/***** Complete this file. *****/

/**
 * The Book class.
 */
class Book
{
public:
    /**
     * Book categories.
     */
    enum class Category { FICTION, HISTORY, TECHNICAL, NONE };

    /**
     * Default constructor.
     */
    Book();

    /**
     * Constructor.
     */
    Book(string isbn, string last, string first, string title, string category);

    /**
     * Destructor.
     */
    ~Book();
	const string& getFirst() const;
	void setFirst(const string& first);
	const string& getIsbn() const;
	void setIsbn(const string& isbn);
	const string& getLast() const;
	void setLast(const string& last);
	const string& getTitle() const;
	void setTitle(const string& title);
	const string& getCategory() const;
	void setCategory(const string& category);

    /***** Complete the public members. *****/

private:
string isbn, last, first, title;
string category;
    /***** Complete the private members. *****/

//operator over loading
friend ostream& operator <<(ostream& out, Book& a );
friend istream& operator >>(istream& out, Book& a );
};
#endif /* EMPLOYEE_H_ */
