extern "C" void _ReadWriteBarrier();
extern void* v1_3ae69f[];
void __stdcall Free(void*, unsigned);
class O_3ae69f {
  public:
    void* vptr;
    O_3ae69f* f2(unsigned char flags);
    void Fin();
};
O_3ae69f* O_3ae69f::f2(unsigned char flags) {
    vptr = v1_3ae69f;
    _ReadWriteBarrier();
    Fin();
    if (flags & 1)
        Free(this, 0x24870000);
    return this;
}
