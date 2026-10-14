extern "C" void __cdecl Copy(void*, void*, unsigned int, unsigned int);
struct S_219730 {
    char pad0[8];
    void* p8;
    void* pc;
    void* p10;
    void* p14;
    void* p18;
    void* p1c;
    void* p20;
    int n24;
    int n28;
    int n2c;
    int n30;
    int n34;
    int n38;
};
void F(void* dst, S_219730* src) {
    Copy(dst, src->pc, src->n2c * 4, 0);
    Copy(dst, src->p10, src->n34 * 4, 0);
    Copy(dst, src->p8, src->n28 * 8, 0);
    Copy(dst, src->p14, src->n30 * 4, 0);
    Copy(dst, src->p18, src->n38 * 12, 0);
    Copy(dst, src->p1c, src->n24 * 4, 0);
    Copy(dst, src, 0x48, 0);
}