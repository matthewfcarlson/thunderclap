extern "C" char DAT_0040d854[];
extern "C" void* __cdecl alloc(unsigned int);
class Face {
  public:
    Face();
    int vf;
    int pad4;
    int m8;
    int mc;
    float m10;
};
class Factory_10c060 {
  public:
    void* f0();
    void* f1();
    void* f2();
    void* f3();
    void* f4();
    Face* vfunc_5();
};
Face* Factory_10c060::vfunc_5() {
    Face* p = (Face*)alloc(0x14);
    if (p) {
        p->Face::Face();
        p->vf = ((int)DAT_0040d854);
        p->mc = 0;
        p->m10 = -1.0f;
        p->m8 = 1;
        return p;
    }
    return 0;
}