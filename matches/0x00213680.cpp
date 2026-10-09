class C { public: char pad0[8]; int *mOut; char pad1[4]; struct A *mA; };
struct A { char pad[0x48]; unsigned int m48; unsigned int m4c; };
void f17440(C*);
int f15f70(int);
int f19cc0(C*,int,int);
void target(C* self,int p2,int p3) { A* a=self->mA; if (a->m4c >= a->m48) f17440(self); int* out=self->mOut; int x=f15f70(p3); int y=f19cc0(self,p2,x+1); out[1]=y; out[0]=5; self->mOut=(int*)((char*)self->mOut+8); }