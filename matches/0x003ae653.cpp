extern "C" void _ReadWriteBarrier();
extern void* v3_3ae653[];
void __stdcall Free(void*, unsigned);
class O_3ae653 {
  public:
    void* vptr;
    O_3ae653* f2(unsigned char flags);
    void Fin();
};
O_3ae653* O_3ae653::f2(unsigned char flags) {
    vptr = v3_3ae653;
    _ReadWriteBarrier();
    Fin();
    if (flags & 1)
        Free(this, 0x24870000);
    return this;
}
