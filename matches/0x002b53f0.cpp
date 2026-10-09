// Same code shape as 0x00085d70 (propagated; names are from that function)
class Obj { public: virtual void f(); virtual void g(); };
extern Obj* globalObj;
void target() { if (globalObj) { globalObj->g(); globalObj = 0; } }