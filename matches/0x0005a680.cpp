// Same code shape as 0x0005a4c0 (propagated; names are from that function)
struct A_5a680 {
    void* first();
};
struct B_5a680 {
    void* second();
};
struct Data_5a680 {
    char pad330[0x330];
    void* p330;
    void* p334;
};
class CGrappleKeyPoseTrack {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual int* vfunc_11(int);
};
int* CGrappleKeyPoseTrack::vfunc_11(int param) {
    if (param) {
        void* a = ((A_5a680*)param)->first();
        if (a) {
            void* b = ((B_5a680*)a)->second();
            if (b) {
                Data_5a680* d = (Data_5a680*)b;
                if (d->p334)
                    return (int*)((char*)d->p334 + 0xdc);
                if (d->p330)
                    return (int*)((char*)d->p330 + 0xdc);
            }
        }
    }
    return 0;
}