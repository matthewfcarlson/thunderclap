typedef unsigned int u32;
typedef unsigned char u8;
void __stdcall InitHelper(const char*, int);
u8 GetHelper(const void*);
struct Obj {
    u32 vptr;
    char p4[12];
    u8 b10;
    char p11[7];
    u8 b18;
    char p19[3];
    void* m1c;
    void* m20;
    Obj* Build(const char*, void*, void*);
};
Obj* Obj::Build(const char* a, void* b, void* c) {
    InitHelper(a, 1);
    vptr = 0x3f407c;
    m1c = c;
    b18 = GetHelper((const void*)0x48e0e4);
    b10 = GetHelper((const void*)0x48e0f0);
    vptr = 0x3f439c;
    m20 = b;
    return this;
}
