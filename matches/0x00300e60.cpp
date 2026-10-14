struct Child_300e60 {
    void F(int);
};
void __fastcall F2(void* self);
void __fastcall F3(void* self);
void __fastcall F4(void* self);
void __cdecl F5(unsigned int n);
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
    F2((char*)p + 0x68);
    F3((char*)p + 0x28);
    F4((char*)p + 0x18);
    p->p3 = p->p2;
    if (p->p2)
        F5(p->p2);
}