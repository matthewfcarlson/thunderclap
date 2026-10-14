class Arg_266510 {
  public:
    virtual void run();
};
class Helper_266510 {
  public:
    void call(void*, void*, Arg_266510*);
};
class LoadObject {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(void*, void*, Arg_266510*);
    virtual void f();
    int x;
    int y;
    Helper_266510* member;
};
void LoadObject::e(void* a, void* b, Arg_266510* arg) {
    Helper_266510* h = member;
    arg->run();
    h->call(a, b, arg);
}