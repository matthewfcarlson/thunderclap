class Ref_13f9c0 {
  public:
    virtual void First();
    virtual void Release();
};
class Base_13f9c0 {
  public:
    int v;
    Base_13f9c0();
};
extern int wallvt;
class WallRunAction : public Base_13f9c0 {
  public:
    char pad[0x18];
    int m1c;
    Ref_13f9c0* m20;
    int m24, m28, m2c, m30, m34, m38, m3c, m40, m44, m48, m4c;
    char m50;
    char pad51[3];
    int m54;
    WallRunAction(int, Ref_13f9c0*);
};
WallRunAction::WallRunAction(int a, Ref_13f9c0* p) {
    v = (int)&wallvt;
    int* q = &m1c;
    *q = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m2c = 0;
    m30 = 0;
    m34 = 0;
    m38 = 0;
    m3c = 0;
    m40 = 0;
    m44 = 0;
    m48 = 0;
    m4c = 0;
    m50 = 0;
    m54 = 0;
    m1c = a;
    if (p)
        p->First();
    if (m20)
        m20->Release();
    m20 = p;
}