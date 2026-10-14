class Track {
  public:
    virtual void* a();
    virtual void* b();
    virtual void* c();
    virtual void* d();
    virtual void* e();
    virtual void* vfunc_5();
    void init();
    int x;
    int y;
    int z;
    int w;
};
extern "C" void* __cdecl malloc(unsigned int);
extern int vftable_159b40;
void* Track::vfunc_5() {
    Track* p = (Track*)malloc(0x14);
    if (p) {
        p->init();
        *(int**)p = &vftable_159b40;
        p->z = 0;
        p->w = 0;
        p->y = 1;
        return p;
    }
    return 0;
}