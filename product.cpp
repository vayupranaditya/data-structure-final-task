#include "app.h"
#include "product.h"

ProductPointer CreateNewProduct(string product_name){
    ProductPointer p=new ProductElement;
    INFO(p).product_name = product_name;
    NEXT(p) = NULL;
    return p;
}

void CreateProductList(ProductList &list){
    FIRST(list) = NULL;
}

ProductPointer FindProduct(string product_name, ProductList list){
    ProductPointer p;
    p = FIRST(list);
    while((INFO(p).product_name != product_name) && (NEXT(p) != NULL)){
        p = NEXT(p);
    }
    if(INFO(p).product_name == product_name){
        return p;
    }else{
        return NULL;
    }
}

void InsertProduct(ProductPointer &product, ProductList &list){
    ProductPointer p;
    if(FIRST(list) != NULL){
        p = FIRST(list);
        while(NEXT(p) != NULL){
            p = NEXT(p);
        }
        NEXT(p) = product;
    }else{
        FIRST(list) = product;
    }
}

ProductPointer DeleteFirstProduct(ProductList &list){
    ProductPointer p;
    if(FIRST(list) != NULL){
        p = FIRST(list);
        if (NEXT(p) == NULL){
            FIRST(list) = NULL;
        }else{
            FIRST(list) = NEXT(p);
            NEXT(p);
        }
        return p;
    }else{
        return NULL;
    }
}

ProductPointer DeleteLastProduct(ProductList &list){
    ProductPointer p;
    if(FIRST(list) != NULL){
        p = FIRST(list);
        while (NEXT(NEXT(p)) != NULL){
            p = NEXT(p);
        }
        NEXT(p) = NULL;
    }
}

ProductPointer DeleteAfterProduct(ProductPointer &precedent, ProductList &list){
    if(precedent!=NULL){
        ProductPointer p=NEXT(precedent);
        NEXT(precedent)=NEXT(p);
        NEXT(p)=NULL;
        return p;
    }else{
        return NULL;
    }
}

void DeleteProduct(ProductPointer &product, ProductList &list){
    if(product!=NULL){
        if (product == FIRST(list)){
            product = DeleteFirstProduct(list);
        }else if(NEXT(product) == NULL){
            product = DeleteLastProduct(list);
        }else{
            ProductPointer p;
            while(NEXT(p)!=product){
                p=NEXT(p);
            }
            product = DeleteAfterProduct(p,list);
        }
    }
}

void UpdateProduct(ProductPointer &product, string product_name){
    //change product_name only.
}

void ViewProduct(ProductList list){
    if(FIRST(list) == NULL){
        cout<<"Empty";
    }else{
        ProductPointer p = FIRST(list);
        while (p != NULL){
            cout<< INFO(p).product_name<<", ";
        }
    }
}