extern "C" void _ReadWriteBarrier();
extern void* v4[];
void __stdcall Free(void*, unsigned);
class O {
  public:
    void* vptr;
    O* f2(unsigned char flags);
    void Fin();
};
O* O::f2(unsigned char flags) {
    vptr = v4;
    _ReadWriteBarrier();
    Fin();
    if (flags & 1)
        Free(this, 0x24870000);
    return this;
}
