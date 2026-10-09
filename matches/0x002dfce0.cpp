class Ref { public: virtual void f0(); virtual void f1(); };
class Base { public: virtual void v(); Base(const Base&); char pad[0x3c]; Ref* ref; int a,b,c,d; };
class PrimGroup : public Base { public: virtual void v(); PrimGroup(const PrimGroup&); };
PrimGroup::PrimGroup(const PrimGroup& other) : Base(other) { ref=0; a=other.a; b=other.b; c=other.c; d=other.d; Ref* p=other.ref; if(p) p->f0(); if(ref) ref->f1(); ref=p; }
