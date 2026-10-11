extern "C" char DAT_0041b248[];
extern void* __cdecl Alloc(unsigned int);
class Item {
  public:
    void Init(int);
};
class Factory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void* F();
};
void* Factory::F() {
    Item* p = (Item*)Alloc(0x10);
    if (p) {
        p->Init(0);
        *(unsigned int*)p = ((int)DAT_0041b248);
        *((char*)p + 0xc) = 1;
    } else {
        return 0;
    }
    return p;
}