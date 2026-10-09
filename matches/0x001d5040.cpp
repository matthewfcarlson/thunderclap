// Same code shape as 0x001d03c0 (propagated; names are from that function)
struct Obj {
    char pad[0x10];
};
Obj* __fastcall FUN_001d03c0(Obj* self) {
    return (Obj*)((char*)self + 0x10);
}