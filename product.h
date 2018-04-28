//product uses single linear linked list with first

#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#include <iostream>
#include "main.h"

using namespace std;

struct ProductInfotype{
	string product_name;
};

struct ProductElement{
	ProductInfotype info;
	ProductPointer next;
};

struct ProductList{
  ProductList(){
    first=NULL;
  }
	ProductPointer first;
};

ProductPointer CreateNewProduct(string product_name);
void CreateProductList(ProductList &list);
ProductPointer FindProduct(string product_name, ProductList list);
void InsertProduct(ProductPointer &product, ProductList &list);   //insert last
ProductPointer DeleteFirstProduct(ProductList &list);
ProductPointer DeleteLastProduct(ProductList &list);
ProductPointer DeleteAfterProduct(ProductPointer &precedent, ProductList &list);
void DeleteProduct(ProductPointer &product, ProductList &list);   //automatically call delete first/after/last
void UpdateProduct(ProductPointer &product, string product_name);
void ViewProduct(ProductList list);
bool IsProductListEmpty(ProductList product_list);

#endif //PRODUCT_H_INCLUDED