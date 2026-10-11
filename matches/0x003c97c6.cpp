extern "C" void _ReadWriteBarrier();
extern void* v[];
void __stdcall Free(void*);
class O {
  public:
    void* vptr;
    O* f2(unsigned char flags);
    void Fin();
};
O* O::f2(unsigned char flags) {
    vptr = v;
    _ReadWriteBarrier();
    Fin();
    if (flags & 1)
        Free(this);
    return this;
}
