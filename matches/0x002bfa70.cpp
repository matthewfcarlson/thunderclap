extern "C" void _ReadWriteBarrier();
extern char ImageFont_vftable[];
class Ref_2bfa70 {
  public:
    virtual void f0();
    virtual void f1();
};
class Base_2bfa70 {
  public:
    void BaseDtor();
};
extern void __cdecl FUN_00263f30(void*);
extern void __cdecl thunk_FUN_00267090(void*);
class ImageFont : public Base_2bfa70 {
  public:
    void* vptr;
    char p[0x24];
    Ref_2bfa70* m28;
    char p2c[8];
    char* m34;
    ImageFont* f2(unsigned char);
};
ImageFont* ImageFont::f2(unsigned char flags) {
    vptr = ImageFont_vftable;
    _ReadWriteBarrier();
    if (m28) {
        m28->f1();
        m28 = 0;
    }
    if (m34)
        thunk_FUN_00267090(m34 - 4);
    BaseDtor();
    if (flags & 1)
        FUN_00263f30(this);
    return this;
}
