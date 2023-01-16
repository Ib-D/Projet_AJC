#include<iostream>
#include "class1.h"

using namespace std;
Class1::Class1()
{
  a=10;
  cout<<"Je suis le constructeur"<<endl;
}

void Class1::afficher()
{
  cout<<"premier affichage "<<"a = "<<a<< endl;
}

Class1::~Class1()
{
  a=10;
  cout<<"Je suis le destructeur"<<endl;
}
