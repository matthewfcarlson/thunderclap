struct Ref { virtual void A(); virtual void B(); };
struct Owner { char pad[0x1c]; Ref* member; void Set(Ref*); };
void Owner::Set(Ref* p) { if (p) p->A(); if (member) member->B(); member = p; }