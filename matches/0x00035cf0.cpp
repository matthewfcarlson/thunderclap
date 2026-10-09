extern const float zero;
class Item { char pad[0x190]; public: int value; };
class Helper { public: int Method(); };
class Obj { public: char pad0[0x11c]; Item *item; char pad120[8]; Helper *thing; char pad12c[0x324-0x12c]; int add; char pad328[0x1b0c-0x328]; float f; int FUN(); };
int Obj::FUN() { int x=100; if(item) x=item->value+100; x+=add; if(thing) x+=thing->Method(); if(f <= zero && x>0) return 0; return x; }