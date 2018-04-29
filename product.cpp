#include "app.h"
#include "product.h"

ProductPointer CreateNewProduct(string product_name){
  ProductPointer p=new ProductElement;
  INFO(p).product_name = product_name;
  INFO(p).average_product=0;
  INFO(p).number=0;
  INFO(p).point=0;
  NEXT(p) = NULL;
  return p;
}

void CreateProductList(ProductList &list){
  FIRST(list) = NULL;
}

ProductPointer FindProduct(string product_name, ProductList list){
  if(FIRST(list)!=NULL){
    ProductPointer p;
    p = FIRST(list);
    while((StrToLower(INFO(p).product_name) != StrToLower(product_name)) && (NEXT(p) != NULL)){
      p = NEXT(p);
    }
    if(StrToLower(INFO(p).product_name) == StrToLower(product_name)){
      return p;
    }else{
      return NULL;
    }
  }
}
void InsertProduct(ProductPointer &product, ProductList &list){
  if(FindProduct(INFO(product).product_name,list)==NULL){
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
}

ProductPointer DeleteFirstProduct(ProductList &list){
  ProductPointer p;
  if(FIRST(list) != NULL){
    p = FIRST(list);
    if (NEXT(p) == NULL){
      FIRST(list) = NULL;
    }else{
      FIRST(list) = NEXT(p);
      NEXT(p)=NULL;
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
    if(NEXT(p)!=NULL){
      while (NEXT(NEXT(p)) != NULL){
        p = NEXT(p);
      }
      ProductPointer q=NEXT(p);
      NEXT(p) = NULL;
      return q;
    }else{
      return DeleteFirstProduct(list);
    }
  }else{
    return NULL;
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
      ProductPointer p=FIRST(list);
      while(NEXT(p)!=product){
      p=NEXT(p);
      }
      product = DeleteAfterProduct(p,list);
    }
  }
}

void UpdateProduct(ProductPointer &product, string product_name){
  if(product!=NULL){
    if((product_name!="") && (INFO(product).product_name!=product_name)){
      INFO(product).product_name=product_name;
    }
  }
}

void ViewProduct(ProductList list){
  if(FIRST(list) == NULL){
    cout<<"Empty";
  }else{
    ProductPointer p = FIRST(list);
    while (p != NULL){
    cout<< INFO(p).product_name<<endl;
    p=NEXT(p);
    }
  }
}

bool IsProductListEmpty(ProductList product_list){
  return FIRST(product_list)==NULL;
}

int CountProduct(ProductList list){
  if(FIRST(list)==NULL){
    return 0;
  }else{
    int i=0;
    ProductPointer p=FIRST(list);
    while(p!=NULL){
      i++;
      p=NEXT(p);
    }
    return i;
  }
}
