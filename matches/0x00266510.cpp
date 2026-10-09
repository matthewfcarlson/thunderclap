class Arg {
  public:
    virtual void run();
};
class Helper {
  public:
    void call(void*, void*, Arg*);
};
class LoadObject {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(void*, void*, Arg*);
    virtual void f();
    int x;
    int y;
    Helper* member;
};
void LoadObject::e(void* a, void* b, Arg* arg) {
    Helper* h = member;
    arg->run();
    h->call(a, b, arg);
}