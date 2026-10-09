typedef unsigned int U;
class Base { public: char pad[0x40]; Base(); };
class PrimGroup : public Base {
public: U a,b,c,d,e;
 PrimGroup(U x,U y);
};
PrimGroup::PrimGroup(U x,U y) { a=0; b=0; c=x; *(U*)this=0x42fb54; d=y; e=0xffffffff; }