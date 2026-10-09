void Release(void*);
struct Obj { char pad[0x30]; int a; int b; char pad2[8]; int c; int d; void f(); };
void Obj::f() { int x = c; d = x; if (x) Release((void*)x); x = a; b = x; if (x) Release((void*)x); }