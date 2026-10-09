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
    *(int*)this = 0x42aee4;
    if (a)
        a->Release();
    if (c)
        c->Release();
    if (b)
        b->Release();
    *(int*)this = 0x3f6098;
}
