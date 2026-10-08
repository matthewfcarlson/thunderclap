class Obj { public: char pad[0x78]; unsigned char index; unsigned char enabled; Obj* Get(); };
Obj* Obj::Get() { if (!enabled) return 0; return (Obj*)((char*)this + index * 12); }