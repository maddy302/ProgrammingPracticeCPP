/*
 * Book.cpp
 *
 *  Created on: 06-Mar-2018
 *      Author: Madhukar
 */

#include "Book.h"
#include <iostream>

Book::Book() {
	// TODO Auto-generated constructor stub

}


Book::Book(string isbn, string last, string first, string title, string category){
this->category = category;
this->isbn = isbn;
this->first = first;
this->last = last;
this->title = title;
}

Book::~Book() {
	// TODO Auto-generated destructor stub
}

const string& Book::getCategory() const {
	return category;
}

void Book::setCategory(const string& category) {
	this->category = category;
}

const string& Book::getFirst() const {
	return first;
}

void Book::setFirst(const string& first) {
	this->first = first;
}

const string& Book::getIsbn() const {
	return isbn;
}

void Book::setIsbn(const string& isbn) {
	this->isbn = isbn;
}

const string& Book::getLast() const {
	return last;
}

void Book::setLast(const string& last) {
	this->last = last;
}

const string& Book::getTitle() const {
	return title;
}

void Book::setTitle(const string& title) {
	this->title = title;
}

 std::ostream& operator <<(std::ostream& out, Book& a ){
	out<<"Book{ISBN="<<a.getIsbn()<<", "<<"last="<<a.getLast();
	out<<", "<<"first="<<a.getFirst();
	out<<", "<<"title="<<a.getTitle();
	out<<", "<<"category="<<a.getCategory()<<"}\n";

	return out;
}

 std::istream& operator >>(std::istream& in,Book& a){

	 return in;
 }
