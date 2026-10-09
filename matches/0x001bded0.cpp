struct Ref { void F(void*); };
struct Obj {
 char pad[0x34]; Ref* a; Ref* b;
 void Clear(void*);
};
void Obj::Clear(void* p) { if (a) a->F(p); if (b) b->F(p); }