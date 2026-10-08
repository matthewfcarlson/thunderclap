struct X { char pad[4]; int a; int b; int c; unsigned char d; char pad2[3]; int e; };
void __fastcall target(X* p, void*) { p->a=0; p->b=-1; p->c=0; p->d=0; p->e=-1; }