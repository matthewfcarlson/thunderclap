// cl-flags: /O1
extern void* v[];
void __stdcall Free(void*, unsigned);
class G {
  public:
    void* vptr;
    void Un(void*) throw();
};
extern G g;
class O {
  public:
    void* vptr;
    O* f2(unsigned char flags);
};
O* O::f2(unsigned char flags) {
    vptr = v;
    g.Un(this);
    if (flags & 1)
        Free(this, 0x24870000);
    return this;
}
