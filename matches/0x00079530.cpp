typedef unsigned __int64 u64;
struct Obj { char pad[0x3650]; u64 FUN_00079530(int index); };
u64 Obj::FUN_00079530(int index) { return *(u64*)((char*)this + (index + 0x365) * 16); }