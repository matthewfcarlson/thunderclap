class Ref {
  public:
    virtual void f();
    virtual void Release();
};
extern int vtable;
class Building {
  public:
    virtual void v();
    char pad[0x7c];
    Ref* a;
    Ref* b;
    Ref* c;
    void init();
    void cleanup();
};
void Building::init() {
    *(int*)this = (int)&vtable;
    if (a)
        a->Release();
    if (b)
        b->Release();
    if (c)
        c->Release();
    cleanup();
}