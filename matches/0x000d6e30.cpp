struct Ref {
    virtual void f0();
    virtual void Release();
};
class COverlayManager {
  public:
    virtual void v0();
    Ref* a;
    char pad[0x24];
    Ref* b;
    void clear();
};
void COverlayManager::clear() {
    *(volatile int*)this = 0x40b370;
    Ref* x = *(Ref* volatile*)&a;
    if (x) {
        x->Release();
        a = 0;
    }
    if (b) {
        b->Release();
        b = 0;
    }
}
