// Same code shape as 0x0006f460 (propagated; names are from that function)
void* __cdecl FUN_0008d690(unsigned int);
class Dummy_17ee20 {
  public:
    int FUN_0005aa00();
};
class Factory_17ee20 {
  public:
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int vfunc_5();
};
int Factory_17ee20::vfunc_5() {
    void* p = FUN_0008d690(0x68);
    if (p)
        return ((Dummy_17ee20*)p)->FUN_0005aa00();
    return 0;
}