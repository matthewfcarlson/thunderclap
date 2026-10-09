struct C {
    char pad[0x4c];
};
void __cdecl f1(void*);
void __cdecl f2(void*);
void __cdecl f3(void*);
void __cdecl f4(void*);
void __fastcall target(C* self) {
    f1(self->pad + 0x4c);
    f2(self->pad + 0x40);
    char* p = self->pad + 8;
    f3(p + 0x14);
    f4(p);
}