extern "C" void* __cdecl alloc(unsigned int);
class S {
  public:
    void Init();
    int vp;
    int unk4;
    int unk8;
    int f0c;
    float f10;
    float f14;
    float f18;
    float f1c;
};
S* __cdecl target() {
    S* p = (S*)alloc(0x20);
    if (p) {
        p->Init();
        p->vp = 0x417c58;
        p->f0c = 0;
        p->f10 = -1.0f;
        p->f14 = 0.0f;
        p->f18 = 0.0f;
        p->f1c = 20.0f;
        p->unk8 = 1;
        return p;
    }
    return 0;
}
