class Obj { public: virtual void A(); virtual void B(); };
class Holder { public: Obj* p; void Set(int unused, Obj* x); };
void Holder::Set(int unused, Obj* x) { if (x) x->A(); if (p) p->B(); p = x; }