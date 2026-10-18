// Same code shape as 0x000679c0 (propagated; names are from that function)
struct C_1c7f70 {
    char pad[0x18];
};
extern int __fastcall FUN_0027af50(C_1c7f70*);
int __fastcall FUN_001c7f70(C_1c7f70* self) {
    return FUN_0027af50((C_1c7f70*)((char*)self + 0x18));
}