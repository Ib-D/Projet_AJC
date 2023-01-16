#include <iostream>
#include "class1.h"

using namespace std;

int main()
{
   Class1 *cl=new Class1;
   cl->afficher();
   cl->b=45;
   cout<<"b = "<<cl->b<<endl;
   delete (cl);
    return 0;
}
