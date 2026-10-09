extern "C" void __cdecl Release(void*);
class MatrixPaletteList {
  public:
    char pad[8];
    void* volatile p;
    void Destroy();
};
void MatrixPaletteList::Destroy() {
    *(volatile unsigned long*)this = 0x42fce4;
    void* q = p;
    if (q)
        Release(q);
    *(volatile unsigned long*)this = 0x3f6098;
}