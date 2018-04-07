//product uses single linear linked list with first

#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#include <iostream>

using namespace std;

struct ProductInfotype{
	string product_name;
};

struct ProductElement{
	ProductInfotype info;
	ProductPointer next;
};

struct ProductList{
	ProductPointer first;
};

ProductPointer CreateNewProduct(sting product_name);
void CreateProductList(ProductList &list);
ProductPointer FindProduct(string product_name, ProductList list);
void InsertProduct(ProductPointer &product, ProductList &list);   //insert last
ProductPointer DeleteFirstProduct(ProductList &list);
ProductPointer DeleteLastProduct(ProductList &list);
ProductPointer DeleteAfterProduct(ProductPointer &precedent ProductList &list);
void UpdateProduct(ProductPointer &product, string product_name);
void ViewProduct(ProductList list);

#endif //PRODUCT_H_INCLUDED