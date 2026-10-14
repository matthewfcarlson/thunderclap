extern "C" void _ReadWriteBarrier();
extern int vt1_2974a0;
class Ref_2974a0 {
  public:
    virtual void f0();
    virtual void Release();
};
class Root_2974a0 {
  public:
    void* vptr;
    ~Root_2974a0() throw();
};
class D : public Root_2974a0 {
  public:
    char pa8[164];
    Ref_2974a0* aa8;
    ~D() throw();
};
D::~D() throw() {
    vptr = &vt1_2974a0;
    _ReadWriteBarrier();
    if (aa8) {
        aa8->Release();
        aa8 = 0;
    }
}
