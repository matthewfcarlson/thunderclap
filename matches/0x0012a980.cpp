extern "C" char DAT_0040fe74[];
class Factory_12a980 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void* Make();
};
extern void* __cdecl FUN_0008d690(unsigned int);
class Init_12a980 {
  public:
    void Start(int);
};
struct Obj_12a980 {
    unsigned int vt;
    int a;
    int b;
    int c;
    int d;
};
void* Factory_12a980::Make() {
    Obj_12a980* p = (Obj_12a980*)FUN_0008d690(0x14);
    if (p) {
        ((Init_12a980*)p)->Start(0);
        p->vt = ((int)DAT_0040fe74);
        p->c = 0;
        p->d = 0;
        return p;
    }
    return 0;
}