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
extern "C" void FUN_00219730(void* dst, void * src) {
    Copy(dst, ((S_219730 *)src)->pc, ((S_219730 *)src)->n2c * 4, 0);
    Copy(dst, ((S_219730 *)src)->p10, ((S_219730 *)src)->n34 * 4, 0);
    Copy(dst, ((S_219730 *)src)->p8, ((S_219730 *)src)->n28 * 8, 0);
    Copy(dst, ((S_219730 *)src)->p14, ((S_219730 *)src)->n30 * 4, 0);
    Copy(dst, ((S_219730 *)src)->p18, ((S_219730 *)src)->n38 * 12, 0);
    Copy(dst, ((S_219730 *)src)->p1c, ((S_219730 *)src)->n24 * 4, 0);
    Copy(dst, ((S_219730 *)src), 0x48, 0);
}