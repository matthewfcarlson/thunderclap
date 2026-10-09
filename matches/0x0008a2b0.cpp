struct A { char p0[0x80]; int x; char p1[0x84]; int y; char p2[0x9ac]; int z; };
int __fastcall f(A* a) { int v = a->z; if (v == 1 && a->x < 10 && a->y > 4) v = 0; return v; }