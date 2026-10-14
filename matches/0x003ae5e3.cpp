extern "C" void _ReadWriteBarrier();
extern void* v5[];
void __stdcall Free(void*, unsigned);
class O_3ae5e3 {
  public:
    void* vptr;
    O_3ae5e3* f2(unsigned char flags);
    void Fin();
};
O_3ae5e3* O_3ae5e3::f2(unsigned char flags) {
    vptr = v5;
    _ReadWriteBarrier();
    Fin();
    if (flags & 1)
        Free(this, 0x24870000);
    return this;
}
