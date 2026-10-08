struct Target { char pad[0x18]; long long value; };
extern "C" long long __cdecl FUN_00267f40();
void __fastcall FUN_0008f160(Target* self) { self->value = FUN_00267f40(); }