extern void* __cdecl FUN_0008d690(unsigned int);
extern int missile_vftable[];
class Prop {
  public:
    int m0;
    int m4;
    char pad[4];
    int mC;
    unsigned char m10;
    void Init(int);
};
class Factory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void* Make();
};
void* Factory::Make() {
    Prop* p = (Prop*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        p->m0 = (int)missile_vftable;
        p->mC = 0;
        p->m10 = 1;
        return p;
    }
    return 0;
}