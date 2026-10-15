typedef unsigned int size_t;
void* operator new(size_t) throw();
class Base {
  public:
    Base() throw();
    virtual void a();
    virtual void b();
    virtual void c();
    int pad;
    int flag;
};
class PrintTrack : public Base {
  public:
    PrintTrack() throw() {
        x = 0;
        y = 0;
        z = 0;
        flag = 1;
    }
    virtual void a();
    int x;
    int y;
    int z;
};
class Factory {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual PrintTrack* vfunc_5();
};
PrintTrack* Factory::vfunc_5() {
    return new PrintTrack;
}