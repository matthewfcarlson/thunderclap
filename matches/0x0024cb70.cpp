struct A { char pad[12]; unsigned x,y,z; }; struct B { unsigned x,y,z; };
void __cdecl target(A* a, B* b) { unsigned *d=&a->x; const unsigned *s=&b->x; d[0]=s[0]; d[1]=s[1]; d[2]=s[2]; }