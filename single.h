#ifndef SINGLE_H_
#define SINGLE_H_

#include <iostream>

#define first(Element) Element->first
#define next(Element) Element->next
#define info(Element) Element->info

using namespace std;

typedef struct CustomerElement* CustomerPointer;
typedef struct ProductElement* ProductPoiter;

struct CustomerInfotype{
	string customer_id, customer_name;
};

struct CustomerElement{
	CustomerInfotype info;
	CustomerPointer next;
};

struct CustomerList{
	CustomerPointer first;
};

struct ProductInfotype{
	string product_id, product_name;
};

struct ProductElement{
	ProductInfotype info;
	ProductPoiter next;
};

struct ProductList{
	ProductPoiter first;
};


#endif SINGLE_H_