extern "C" void _ReadWriteBarrier();
extern void* v2_3ae679[];
void __stdcall Free(void*, unsigned);
class O_3ae679 {
  public:
    void* vptr;
    O_3ae679* f2(unsigned char flags);
    void Fin();
};
O_3ae679* O_3ae679::f2(unsigned char flags) {
    vptr = v2_3ae679;
    _ReadWriteBarrier();
    Fin();
    if (flags & 1)
        Free(this, 0x24870000);
    return this;
}
