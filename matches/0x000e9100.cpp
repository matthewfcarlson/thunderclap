class Thing { public: virtual void A(); virtual void B(); };
class Owner { public: char pad[0x60]; Thing* mThing; void Set(Thing* p); };
void Owner::Set(Thing* p) { if (p) p->A(); if (mThing) mThing->B(); mThing = p; }