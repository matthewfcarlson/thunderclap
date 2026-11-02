struct C_25def0 {
    char pad[0x4c];
};
void __cdecl f1(void*);
void __cdecl f2(void*);
extern "C" void __cdecl FUN_0024a450(void*);
extern "C" void __cdecl FUN_0024a4a0(void*);
void __fastcall target(C_25def0* self) {
    f1(self->pad + 0x4c);
    f2(self->pad + 0x40);
    char* p = self->pad + 8;
    FUN_0024a450(p + 0x14);
    FUN_0024a4a0(p);
}