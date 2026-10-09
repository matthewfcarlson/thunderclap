class X { public: char pad[12]; int a,b; int *p; };
int __fastcall target(X* x) {
 int r;
 if (x->a) {
   int n=x->b;
   r=0;
   if(n>=0) {
     int *p=x->p;
     ++n;
     do { if(*p) ++r; ++p; --n; } while(n);
   }
   return r;
 }
 return x->b+1;
}