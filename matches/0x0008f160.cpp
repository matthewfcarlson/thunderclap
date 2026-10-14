struct Target_8f160 {
    char pad[0x18];
    long long value;
};
extern "C" long long __cdecl FUN_00267f40();
void __fastcall FUN_0008f160(Target_8f160* self) {
    self->value = FUN_00267f40();
}