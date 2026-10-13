// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002fcf30 @ 0x002fcf30
struct Vector { float x,y,z; };
struct Tensor {
 char pad[4]; float a,b,c,d,e,f;
 void FUN_002fcf30(const Vector* v);
};
void Tensor::FUN_002fcf30(const Vector* v) {
 volatile float A=c*v->y-v->z*b;
 volatile float B=e*v->y-v->z*d;
 double C=(double)f*v->y-(double)v->z*e;
 volatile float roundedC=(float)C;
 float na=(float)(C*v->y-(double)B*v->z);
 float nc=(float)((double)B*v->x-(double)A*v->y);
 float nb=(float)((double)A*v->z-(double)roundedC*v->x);
 double D=(double)v->z*a-(double)c*v->x;
 float nd=(float)(D*v->z-((double)v->z*c-(double)v->x*f)*v->x);
 float ne=(float)(-(D*v->y));
 float nf=(float)(((double)d*v->x-(double)v->y*b)*v->x-((double)v->x*b-(double)a*v->y)*v->y);
 d=nd; e=ne; f=nf; a=na; b=nb; c=nc;
}