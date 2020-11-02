#include <conio.h>
#include <iostream>
using namespace std;
// Clasa "Desen"
class Punct {
      float x,y;
   public:
      Punct(float x = 0, float y = 0);
      void setX(float x);
      float getX();
      void setY(float y);
      float getY();
      friend ostream & operator << (ostream &out, Punct &p);
};

Punct:: Punct(float x, float y){
      this->x = x; this->y = y;
}

void Punct::setX(float x){
      this->x = x;
}

float Punct::getX(){
      return x;
}

void Punct::setY(float y){
      this->y = y;
}

float Punct::getY(){
      return y;
}

ostream & operator << (ostream &out, Punct &p){
    out<<"("<<p.x<<","<<p.y<<")";
    return out;
}
class FiguraGeometrica {
      public:
         virtual void print();
         virtual ~FiguraGeometrica();
};


void FiguraGeometrica::print(){
     cout<<"Figura Geometrica Oarecare"<<endl;
}
FiguraGeometrica::~FiguraGeometrica(){
     cout<<"Apel destructor FiguraGeometrica"<<endl;
}

class Cerc: public FiguraGeometrica {
        Punct centru;
        float raza;
      public:
        Cerc (Punct c, float r);
        Cerc();
        void print();
};
Cerc::Cerc(Punct c, float r):centru(c), raza(r){
}
void Cerc::print(){
     cout<<"Cerc ("<<centru<<","<<raza<<")"<<endl;
}
Cerc::~Cerc(){
     cout<<"Apel destructor Cerc"<<endl;
}

class Dreptunghi: public FiguraGeometrica {
      Punct colt_s_s; //colt stanga sus
      Punct colt_d_j; //colt dreapta jos
     public:
      Dreptunghi (Punct c_s_s, Punct c_d_j);
      ~Dreptunghi();
      void print();
};

Dreptunghi::Dreptunghi(Punct c_s_s, Punct c_d_j): colt_s_s(c_s_s), colt_d_j(c_d_j){
}

void Dreptunghi::print(){
     cout<<"Dreptunghi ["<<colt_s_s<<","<<colt_d_j<<"]"<<endl;;
}
Dreptunghi::~Dreptunghi(){
     cout<<"Apel destructor Dreptunghi"<<endl;
}

class Plansa {
      FiguraGeometrica **pFiguri;
      int nrFiguri;
   public:
       Plansa(int n, FiguraGeometrica *f[]);
       Plansa(const Plansa &plansa);
       ~Plansa();
       void print();
};
Plansa::Plansa(int n, FiguraGeometrica *f[]){
     nrFiguri=n;
     pFiguri = new FiguraGeometrica*[nrFiguri];
     for(int i=0;i<nrFiguri;i++){
       pFiguri[i] = f[i];
     }
}

Plansa::Plansa(const Plansa &plansa){
     nrFiguri=plansa.nrFiguri;
     pFiguri = new FiguraGeometrica*[nrFiguri];
     for(int i=0;i<nrFiguri;i++){
       pFiguri[i] = plansa.pFiguri[i];
     }
}
Plansa::~Plansa(){
    if (pFiguri != 0){
        delete pFiguri;
        pFiguri = 0;
    }
}

void Plansa::print(){
     cout<<"Plansa:"<<endl;
     cout<<"======================================="<<endl;
     for(int i=0;i<nrFiguri;i++){
       if (pFiguri[i]!=0){
          pFiguri[i]->print();
       }
     }
    cout<<"======================================="<<endl;
}
int main(){
    Cerc c(Punct(0,0),1);
    c.print();
    Dreptunghi d(Punct(0,1),Punct(2,0));
    d.print();
    FiguraGeometrica *f[]={&c,&d};
    Plansa plansa(2,f);
    plansa.print();
}
