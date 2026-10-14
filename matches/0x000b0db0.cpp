class Owner_b0db0 {
  public:
    virtual void A();
    virtual void Release();
};
class Obj_b0db0 {
  public:
    char pad0[0x10];
    Owner_b0db0* p;
    void Run();
};
void cleanup(int, int, void*, void*, void*);
void Obj_b0db0::Run() {
    if (p) {
        cleanup(0xd, 2, (char*)this + 0x3e4, (char*)this + 0x418, (char*)this + 0x488);
        cleanup(0xb, 2, (char*)this + 0x358, (char*)this + 0x384, (char*)this + 0x48c);
        if (p) {
            p->Release();
            p = 0;
        }
    }
}