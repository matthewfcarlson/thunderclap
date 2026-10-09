class C { public: char pad[0x58c]; int count; void f(int); };
struct E { char x[0x50]; int key; char y[0x10]; char flag; };
void C::f(int key) { int n=count; int i=0; if(n>0) { E* p=(E*)((char*)this+0x590); do { if(p->key==key) { p->flag=1; return; } ++i; p=(E*)((char*)p+0x68); } while(i<n); } }