extern "C" char DAT_0041b248[];
extern void* __cdecl Alloc(unsigned int);
class Item_1a0d30 {
  public:
    void Init(int);
};
class Factory_1a0d30 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void* F();
};
void* Factory_1a0d30::F() {
    Item_1a0d30* p = (Item_1a0d30*)Alloc(0x10);
    if (p) {
        p->Init(0);
        *(unsigned int*)p = ((int)DAT_0041b248);
        *((char*)p + 0xc) = 1;
    } else {
        return 0;
    }
    return p;
}