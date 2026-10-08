// Same code shape as 0x002226e0 (propagated; names are from that function)
class Inner { public: void call(); };
class Obj { public: char pad[0x10]; void target(); };
void Obj::target() { ((Inner*)((char*)this + 0x10))->call(); }