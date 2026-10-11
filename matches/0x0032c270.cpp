extern "C" char DAT_00433a04[];
class Base {
  public:
    virtual void f();
    virtual void Release();
};
class Obj {
  public:
    virtual void f();
    char pad[0x7c];
    Base* a;
    Base* b;
    void Run();
    void Tail();
};
void Obj::Run() {
    Base* p = a;
    *(int*)this = ((int)DAT_00433a04);
    if (p)
        p->Release();
    p = b;
    if (p)
        p->Release();
    Tail();
}
