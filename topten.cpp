#include "app.h"
#include "topten.h"
#include "product.h"

using namespace std;

AverageRatePointer CreateNewAverage(float average_product, ProductPointer product){
  AverageRatePointer average=new AverageRateElement;
  INFO(average).average_product=average_product;
  NEXT(average)=NULL;
  PRODUCT(average)=product;
  return average;
}

void CreateAverageList(AverageRateList &list){
  FIRST(list)=NULL;
  LAST(list)=NULL;
}

AverageRatePointer FindAverage(string product_name, AverageRateList list){
  if(FIRST(list)!=NULL){
    AverageRatePointer p=FIRST(list);
    while((p->product->info.product_name!=product_name)&&(p!=LAST(list))){
      p=NEXT(p);
    }
    if(p->product->info.product_name!=product_name){
      return p;
    }else{
      return NULL;
    }
  }
}

void InsertAverage(ProductPointer product, int point, AverageRateList list){
  float average_product;
  if(FindAverage(INFO(product).product_name,list)==NULL){
    AverageRatePointer average=CreateNewAverage(average_product, product);
    if(FIRST(list)==NULL){
      FIRST(list)=average;
      LAST(list)=average;
      NEXT(average)=NULL;
      PREVIOUS(average)=NULL;
    }else{
      PREVIOUS(average)=LAST(list);
      NEXT(PREVIOUS(average))=average;
      LAST(list)=average;
    }
  }else{
    AverageRatePointer average=FindAverage(INFO(product).product_name, list);
    INFO(average).lots_of_data++;
    INFO(average).amount_of_data=INFO(average).amount_of_data+point;
    INFO(average).average_product=INFO(average).amount_of_data/INFO(average).lots_of_data;
  }
}

AverageRatePointer DeleteFirstAverage(AverageRateList &list){
  if(FIRST(list)!=NULL){
    AverageRatePointer p=FIRST(list);
    if(FIRST(list)==LAST(list)){
      FIRST(list)=NULL;
      LAST(list)=NULL;
    }else{
      FIRST(list)=NEXT(FIRST(list));
      PREVIOUS(FIRST(list))=NULL;
      NEXT(p)=NULL;
      return p;
    }
  }else{
    return NULL;
  }
}

AverageRatePointer DeleteLastAverage(AverageRateList &list){
  if(FIRST(list)!=NULL){
    if(FIRST(list)==LAST(list)){
      return DeleteFirstAverage(list);
    }else{
      AverageRatePointer p=LAST(list);
      LAST(list)=PREVIOUS(LAST(list));
      NEXT(LAST(list))=NULL;
      PREVIOUS(p)=NULL;
      return p;
    }
  }else{
    return NULL;
  }
}

AverageRatePointer DeleteAfterAverage(AverageRatePointer &precedent, AverageRateList &list){
  if(precedent!=NULL){
    AverageRatePointer p=NEXT(precedent);
    NEXT(precedent)=NEXT(p);
    PREVIOUS(NEXT(precedent))=precedent;
    NEXT(p)=NULL;
    PREVIOUS(p)=NULL;
    return p;
  }else{
    return NULL;
  }
}

void DeleteAverage(AverageRatePointer &average, AverageRateList &list){
  if(average!=NULL){
    if(average==FIRST(list)){
      average=DeleteFirstAverage(list);
    }else if(average==LAST(list)){
      average=DeleteLastAverage(list);
    }else{
      average=DeleteAfterAverage(PREVIOUS(average),list);
    }
  }
}

void SortTopTen(AverageRateList list){
  AverageRatePointer maks=FIRST(list);
  AverageRatePointer p=NEXT(maks);
  while(p!=LAST(list)){
    while(INFO(maks).average_product<INFO(p).average_product){
      maks=p;
    }
    p=NEXT(p);
  }
  DeleteAverage(maks, list);
  cout<<maks;
}
