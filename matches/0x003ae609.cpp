extern "C" void _ReadWriteBarrier();
extern void* v4_3ae609[];
void __stdcall Free(void*, unsigned);
class O_3ae609 {
  public:
    void* vptr;
    O_3ae609* f2(unsigned char flags);
    void Fin();
};
O_3ae609* O_3ae609::f2(unsigned char flags) {
    vptr = v4_3ae609;
    _ReadWriteBarrier();
    Fin();
    if (flags & 1)
        Free(this, 0x24870000);
    return this;
}
