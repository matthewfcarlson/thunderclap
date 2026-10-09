class MixBuss {
  public:
    virtual void v0();
    virtual int v1(void*);
    char pad[0x10];
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
};
extern "C" bool FUN_0024f010(void*, void*);
extern "C" bool FUN_0025ac10(void*, void*);
extern "C" bool FUN_0025aa80(void*, void*);
int MixBuss::v1(void* p) {
    if (FUN_0024f010(p, &a) && FUN_0025ac10(p, &b) && FUN_0025ac10(p, &c) && FUN_0025ac10(p, &d) &&
        FUN_0025ac10(p, &e) && FUN_0025aa80(p, &f))
        return 1;
    return 0;
}