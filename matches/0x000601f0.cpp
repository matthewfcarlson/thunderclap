class Sub { public: void Call(); };
class Obj { char pad[0x140]; public: Obj* F(); void G(); };
Obj* Obj::F() { ((Sub*)((char*)this + 0x140))->Call(); G(); return this; }
