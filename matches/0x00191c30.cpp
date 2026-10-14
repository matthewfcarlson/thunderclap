void* __cdecl operator_new(unsigned int);
struct Init_191c30 {
    int initialize();
};
class Factory_191c30 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual int create();
};
int Factory_191c30::create() {
    Init_191c30* p = (Init_191c30*)operator_new(0x74);
    if (p)
        return p->initialize();
    return 0;
}