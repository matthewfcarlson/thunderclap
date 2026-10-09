void* __cdecl operator_new(unsigned int);
struct Init {
    int initialize();
};
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual int create();
};
int Factory::create() {
    Init* p = (Init*)operator_new(0x74);
    if (p)
        return p->initialize();
    return 0;
}