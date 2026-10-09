class Ref { public: virtual void A(); virtual void B(); };
class Owner { char pad[0x44]; Ref* mRef; public: void Set(class Source*); };
class Source { public: char pad[0x68]; Ref* mRef; };
void Owner::Set(Source* src) { Ref* p = src->mRef; if (p) p->A(); if (mRef) mRef->B(); mRef = p; }