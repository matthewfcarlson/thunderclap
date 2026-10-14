class Ref_ce850 {
  public:
    virtual void f();
    virtual void Release();
};
class Obj_ce850 {
  public:
    char p0[0x14];
    Ref_ce850* a;
    Ref_ce850* b;
    char p1[0x0c];
    int x[10];
    unsigned char flag;
    char p2[0x33];
    int value;
    void reset();
};
void Obj_ce850::reset() {
    if (a) {
        a->Release();
        a = 0;
    }
    if (b) {
        b->Release();
        b = 0;
    }
    flag = 0;
    value = 0xff;
    for (int i = 0; i < 10; i++)
        x[i] = 0;
}
