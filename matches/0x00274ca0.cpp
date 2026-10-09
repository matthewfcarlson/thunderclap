void init();
class Intf {
  public:
    virtual void f0();
    virtual void f1();
};
class Obj {
  public:
    virtual void v0();
    Intf sub;
    char pad[0x10];
    int count;
};
class Target {
  public:
    virtual void Go();
};
class FileCompletionRequest {
  public:
    int v;
    int a;
    int b;
    Obj* c;
    Target* d;
    int e;
    FileCompletionRequest(int x, Obj* y, Target* z, int w);
};
FileCompletionRequest::FileCompletionRequest(int x, Obj* y, Target* z, int w) {
    v = 0x42b914;
    a = 0;
    init();
    v = 0x42b9dc;
    b = x;
    init();
    v = 0x42b954;
    c = y;
    d = z;
    e = w;
    init();
    d->Go();
    c->sub.f0();
    c->count++;
    c->sub.f1();
    c->v0();
}
