class Obj { public: virtual void F0(); virtual void F1(); };
class Holder { public: char pad[8]; Obj* p; void Set(Obj* value); };
void Holder::Set(Obj* value) { if (value) value->F0(); if (p) p->F1(); p = value; }