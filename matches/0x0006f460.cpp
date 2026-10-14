void* __cdecl FUN_0008d690(unsigned int);
class Dummy_6f460 {
  public:
    int FUN_0005aa00();
};
class Factory_6f460 {
  public:
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int vfunc_5();
};
int Factory_6f460::vfunc_5() {
    void* p = FUN_0008d690(0x68);
    if (p)
        return ((Dummy_6f460*)p)->FUN_0005aa00();
    return 0;
}