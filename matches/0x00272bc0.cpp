struct Obj { char pad[0x14]; };
void* __fastcall target(Obj* self) { return (char*)self + 0x14; }