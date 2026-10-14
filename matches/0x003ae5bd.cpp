extern "C" void _ReadWriteBarrier();
extern void* v6[];
void __stdcall Free(void*, unsigned);
class O_3ae5bd {
  public:
    void* vptr;
    O_3ae5bd* f2(unsigned char flags);
    void Fin();
};
O_3ae5bd* O_3ae5bd::f2(unsigned char flags) {
    vptr = v6;
    _ReadWriteBarrier();
    Fin();
    if (flags & 1)
        Free(this, 0x24870000);
    return this;
}
