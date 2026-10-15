// Same code shape as 0x0005a4c0 (propagated; names are from that function)
struct A_5b620 {
    void* first();
};
struct B_5b620 {
    void* second();
};
struct Data_5b620 {
    char pad330[0x330];
    void* p330;
    void* p334;
};
class CGrappleSmartPropDropTrack {
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
int* CGrappleSmartPropDropTrack::vfunc_11(int param) {
    if (param) {
        void* a = ((A_5b620*)param)->first();
        if (a) {
            void* b = ((B_5b620*)a)->second();
            if (b) {
                Data_5b620* d = (Data_5b620*)b;
                if (d->p334)
                    return (int*)((char*)d->p334 + 0xdc);
                if (d->p330)
                    return (int*)((char*)d->p330 + 0xdc);
            }
        }
    }
    return 0;
}