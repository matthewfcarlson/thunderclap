extern "C" char DAT_003f6098[];
extern "C" char DAT_0042aee4[];
class Ref {
  public:
    virtual void A();
    virtual void Release();
};
class LoadRequest {
  public:
    virtual void A();
    char pad14[0x14];
    Ref* a;
    Ref* b;
    char pad20[0x104];
    Ref* c;
    void Destroy();
};
void LoadRequest::Destroy() {
    *(int*)this = ((int)DAT_0042aee4);
    if (a)
        a->Release();
    if (c)
        c->Release();
    if (b)
        b->Release();
    *(int*)this = ((int)DAT_003f6098);
}
