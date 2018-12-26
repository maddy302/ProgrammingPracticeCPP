/*
 * Node.cpp
 *
 *  Created on: 22-Apr-2018
 *      Author: Madhukar
 */

#include "Node.h"
#include "Element.h"

/***** Complete this file. *****/
Node::Node(){
this->next = nullptr;
}

Node::Node(Element e){
this->element = e;
this->next = nullptr;
}

Node::~Node(){

}
