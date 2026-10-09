class HoverTrack {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    char pad[4];
    int one;
    int a;
    int b;
    int c;
};
extern "C" void* __cdecl Alloc(unsigned int);
void __fastcall Init(HoverTrack*);
class Factory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual HoverTrack* Make();
};
HoverTrack* Factory::Make() {
    HoverTrack* p = (HoverTrack*)Alloc(0x18);
    if (p) {
        Init(p);
        *(int*)p = 0x411ca8;
        p->a = 0;
        p->b = (int)0xbf800000;
        p->c = 0;
        p->one = 1;
        return p;
    }
    return 0;
}