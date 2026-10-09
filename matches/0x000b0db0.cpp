class Owner {
  public:
    virtual void A();
    virtual void Release();
};
class Obj {
  public:
    char pad0[0x10];
    Owner* p;
    void Run();
};
void cleanup(int, int, void*, void*, void*);
void Obj::Run() {
    if (p) {
        cleanup(0xd, 2, (char*)this + 0x3e4, (char*)this + 0x418, (char*)this + 0x488);
        cleanup(0xb, 2, (char*)this + 0x358, (char*)this + 0x384, (char*)this + 0x48c);
        if (p) {
            p->Release();
            p = 0;
        }
    }
}