class Context { public: int Query(int); };
class Obj { public: char pad[0x40]; int arg; char pad2[0xa8]; Context* ctx; };
struct Slot { Obj* p; char pad[0x4c]; };
class Owner { public: char pad[0x3a8]; Slot items[8]; int Find(); };
int Owner::Find() { for (int i=0; i<8; ++i) { Obj* p=items[i].p; if (p) { int a=p->arg; Context* c=p->ctx; if (c->Query(a)==2) return i; } } return -1; }
