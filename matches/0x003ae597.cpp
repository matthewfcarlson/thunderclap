extern "C" void _ReadWriteBarrier();
extern void* v7[];
void __stdcall Free(void*, unsigned);
class O_3ae597 {
  public:
    void* vptr;
    O_3ae597* f2(unsigned char flags);
    void Fin();
};
O_3ae597* O_3ae597::f2(unsigned char flags) {
    vptr = v7;
    _ReadWriteBarrier();
    Fin();
    if (flags & 1)
        Free(this, 0x24870000);
    return this;
}
