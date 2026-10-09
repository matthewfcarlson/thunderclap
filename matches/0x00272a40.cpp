class Inner { public: virtual void A(); virtual void B(); };
class Other { public: void Run(int); };
class Obj { public: char pad0[0x0c]; Inner inner; char pad10[0x44]; unsigned char flag; int value; char pad60[0x5c]; Other* other; void Target(int); };
void Obj::Target(int arg) { inner.A(); flag = 0; value = 0; inner.B(); other->Run(arg); }