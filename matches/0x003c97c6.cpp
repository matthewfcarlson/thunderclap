extern "C" void _ReadWriteBarrier();
extern void* v_3c97c6[];
void __stdcall Free(void*);
class O_3c97c6 {
  public:
    void* vptr;
    O_3c97c6* f2(unsigned char flags);
    void Fin();
};
O_3c97c6* O_3c97c6::f2(unsigned char flags) {
    vptr = v_3c97c6;
    _ReadWriteBarrier();
    Fin();
    if (flags & 1)
        Free(this);
    return this;
}
