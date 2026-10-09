void* __cdecl alloc_block(unsigned int);
unsigned int __fastcall construct_camera(void*);
class TrackFactoryTemplate {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual unsigned int vfunc_5();
};
unsigned int TrackFactoryTemplate::vfunc_5() {
    void* p = alloc_block(0xa0);
    if (p)
        return construct_camera(p);
    return 0;
}