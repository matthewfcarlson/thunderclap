extern "C" char DAT_003f3390[];
extern "C" char DAT_003f37f4[];
class Ref {
  public:
    virtual void A();
    virtual void B();
};
extern void Init();
class CGrabAction {
  public:
    int* vptr;
    char pad04[0x18];
    Ref* first;
    int m20;
    int m24;
    int m28;
    char pad2c[12];
    char m38;
    char pad39[3];
    Ref* second;
    CGrabAction(Ref*, int, Ref*, int);
};
CGrabAction::CGrabAction(Ref* a, int b, Ref* c, int d) {
    Init();
    vptr = (int*)((int)DAT_003f3390);
    first = 0;
    if (c)
        c->A();
    if (first)
        first->B();
    first = c;
    vptr = (int*)((int)DAT_003f37f4);
    m24 = d;
    m28 = 0;
    m38 = 0;
    second = 0;
    m20 = b;
    if (a)
        a->A();
    if (second)
        second->B();
    second = a;
}