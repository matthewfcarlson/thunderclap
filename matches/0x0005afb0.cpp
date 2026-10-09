// Same code shape as 0x0005adb0 (propagated; names are from that function)
struct Obj {
    char pad[0x330];
    int* p330;
    int* p334;
};
struct Context {
    Obj* first();
    Obj* second();
};
class CGrappleOpportunityTrack {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual int* vfunc_8(void*, void*);
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
};
int* CGrappleOpportunityTrack::vfunc_8(void*, void* p) {
    if (!p)
        return 0;
    Obj* a = ((Context*)p)->first();
    if (!a)
        return 0;
    Obj* b = ((Context*)a)->second();
    if (!b)
        return 0;
    if (b->p334)
        return (int*)((char*)b->p334 + 0xdc);
    if (b->p330)
        return (int*)((char*)b->p330 + 0xdc);
    return 0;
}