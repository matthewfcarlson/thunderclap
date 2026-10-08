struct Base { void FUN_00088fe0(); };
struct Obj { char pad[0x80]; void FUN_00089810(); };
void Obj::FUN_00089810() { ((Base*)((char*)this + 0x80))->FUN_00088fe0(); }