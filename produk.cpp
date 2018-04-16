#include "product.h"

ProductPointer CreateNewProduct(string product_name){
    ProductPointer P = new ProductElement;
    info(p) = product_name;
    next(p) = NULL;
    return p;
}

void CreateProductList(ProductList &list){
    first(list) = NULL;
}

ProductPointer FindProduct(string product_name, ProductList list){
    ProductPointer p;
    p = first(list);
    while ((info(p) != produect_name) && (next(p) != NULL)){
        p = next(p);
    }
    if (info(p) == product_name){
        return p;
    }
    else{
        return NULL;
    }
}

void InsertProduct((ProductPointer &product, ProductList &list)){
    ProductPointer p;
    if (first(list) != NULL){
        p = first(list);
    while (next(product) != NULL){
        p = next(p);
    }
    next(p) = product;
    }
    else {
        first(list) = product;
    }
}

ProductPointer DeleteFirstProduct(ProductList &list){
    ProductPointer p;
    if ((first(list)) != NULL){
        p = first(list)
        if (next(p)) == NULL){
            first(list) = NULL;
        }
        else{
            first(list) = next(p);
            next(p);
        }
        return p;
    }
}

ProductPointer DeleteLastProduct(ProductList &list){
    ProductPointer p;
    if (first(list) != NULL){
        p = first(list);
        while (next(next(p)) != NULL){
            p = next(p);
        }
        next(p) = NULL;
    }
}

ProductPointer DeleteAfterProduct(ProductPointer &precedent, ProductList &list){
    ProductPointer p;
    if (first(list) != NULL){
         p = first(list);
         p = FindProduct(product_name, list);
         if (p == first(list)){
            p = DeleteFirstProduct(list);
         }
         else if (next(next(p)) == NULL){
            p = DeleteLastProduct(list)
         }
         else{
            next(p) = next(precedent));
            next(precedent) =  NULL;
         }
    }
}

void DeleteProduct(ProductPointer &product, ProductList &list){
    if (product == first(list)){
        product = DeleteFirstProduct(list);
    }
    else if (next(product) == NULL){
        product = DeleteLastProduct(list);
    }
    else{
        product = DeleteAfterProduct(list);
    }
}

void UpdateProduct(ProductPointer &product, string product_name){

}

void ViewProduct(ProductList list){
    if(first(list) == NULL){
        cout<<"List Kosong";
    } else{
        address p = first(list);
        while ( p != NULL){
            cout<< info(p)<<", ";
        }
    }
}
