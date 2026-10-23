struct Child_300e60 {
    void F(int);
};
void __fastcall FUN_002f79f0(void* self);
void __fastcall FUN_003012c0(void* self);
void __fastcall FUN_00304350(void* self);
void __cdecl FUN_0008d340(unsigned int n);
struct Obj_300e60 {
    Child_300e60* first;
    unsigned int x;
    unsigned int p2;
    unsigned int p3;
    char pad[0x54];
};
void __fastcall Target(Obj_300e60* p) {
    if (p->first)
        p->first->F(3);
    FUN_002f79f0((char*)p + 0x68);
    FUN_003012c0((char*)p + 0x28);
    FUN_00304350((char*)p + 0x18);
    p->p3 = p->p2;
    if (p->p2)
        FUN_0008d340(p->p2);
}