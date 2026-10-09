class Obj {
  public:
    char pad0[0x68];
    int count;
    char pad1[0x280];
    unsigned char dirty;
};
extern "C" void __cdecl Move(void*, void*, int);
void __fastcall Target(Obj* p) {
    if (p->dirty) {
        char* end = (char*)p + 0x6c + p->count * 0x28;
        p->dirty = 0;
        char* base = (char*)p + 0x6c;
        Move(base, end, (int)(end - base) / 0x28);
    }
}