// Same code shape as 0x00091d50 (propagated; names are from that function)
struct Obj { char pad[0x68]; Obj* Get(); };
Obj* Obj::Get() { return (Obj*)((char*)this + 0x68); }