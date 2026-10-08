struct A { int pad; unsigned int x; };
unsigned int __fastcall FUN_00099790(A* a) { return (a->x >> 3) & 1; }