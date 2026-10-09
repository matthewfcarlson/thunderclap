class Ref { public: virtual void A(); virtual void B(); };
class Owner { char pad[0x1dc]; Ref* p; public: void Set(Ref*); };
void Owner::Set(Ref* value) { if ((void*)this != (void*)value) { if (value) value->A(); if (p) p->B(); p = value; } }