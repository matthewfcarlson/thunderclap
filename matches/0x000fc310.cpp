struct S { char pad[0x175c]; int value; };
extern S *g;
int f() { return g->value; }