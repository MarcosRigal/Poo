#include <iostream>
using namespace std;

template <class T> class MiClase
{
   private:
      
      T x_, y_;
   
   public:
      
      MiClase (T a, T b){ x_=a; y_=b;};
      inline T div(){return x_/y_;};
      inline T prod(){return x_*y_;};
      inline T dif(){return x_-y_;};
      inline T sum(){return x_+y_;};
};

int main()
{

   MiClase <int> iobj(10,3);
   MiClase <double> dobj(3.3, 5.5);
   cout << "división entera = " << iobj.div() << endl;
   cout << "división real = " << dobj.div() << endl;
   cout << "producto entera = " << iobj.prod() << endl;
   cout << "producto real = " << dobj.prod() << endl;
   cout << "diferencia entera = " << iobj.dif() << endl;
   cout << "diferencia real = " << dobj.dif() << endl;
   cout << "suma entera = " << iobj.sum() << endl;
   cout << "suma real = " << dobj.sum() << endl;
}
