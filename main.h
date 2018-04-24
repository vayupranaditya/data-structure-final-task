/*
 *main.h used for functions, defining, type, etc. outside any data list or for usage in more than one list
 *however, custom function, defining, type, etc. for any specific list may be created in their own header file
 *this project uses Google C++ Style Guide: https://google.github.io/styleguide/cppguide.html
 */

#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

using namespace std;

#define FIRST(Element) Element.first
#define LAST(Element) Element.last
#define NEXT(Element) Element->next
#define PREVIOUS(Element) Element->previous
#define INFO(Element) Element->info

typedef struct CustomerElement* CustomerPointer;
typedef struct ProductElement* ProductPointer;

#endif //MAIN_H_INCLUDED