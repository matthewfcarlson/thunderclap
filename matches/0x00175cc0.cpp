class Ref {
  public:
    virtual void Add();
    virtual void Release();
};
class Helper {
  public:
    void Init();
    void InitSub();
};
class Teleport {
  public:
    int vptr;
    char pad[0x18];
    int value;
    Ref* ref;
    char pad2[4];
    Helper sub;
    Teleport(int x, Ref* r);
};
Teleport::Teleport(int x, Ref* r) {
    ((Helper*)this)->Init();
    vptr = 0x417f48;
    value = 0;
    ref = 0;
    sub.InitSub();
    value = x;
    if (r)
        r->Add();
    if (ref)
        ref->Release();
    ref = r;
}
