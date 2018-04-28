#ifndef TOPTEN_H_INCLUDED
#define TOPTEN_H_INCLUDED

typedef struct AverageRateElement* AverageRatePointer;

struct AverageRateInfotype{
  float average_product;
  int lots_of_data;
  int amount_of_data;
};

struct AverageRateElement{
  AverageRateInfotype info;
  ProductPointer product;
  AverageRatePointer next, previous;
};

struct AverageRateList{
  AverageRateList(){
    first=NULL;
    last=NULL;
  }
  AverageRatePointer first, last;
};



#endif // TOPTEN_H_INCLUDED
