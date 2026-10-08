struct Obj { char pad[0x68]; Obj* Get(); };
Obj* Obj::Get() { return (Obj*)((char*)this + 0x68); }