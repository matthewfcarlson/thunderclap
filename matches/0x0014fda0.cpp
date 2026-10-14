class Mid_14fda0 {
  public:
    Mid_14fda0* Touch();
    void Draw(float, int, int, int, int, unsigned char);
};
class Thing_14fda0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int d();
    char pad[0x48 - 4];
    int x48;
    int x4c;
    char p[0x78 - 0x50];
    float x78;
    int x7c;
    char p2[0x91 - 0x80];
    unsigned char x91;
};
class Ref_14fda0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual Thing_14fda0* d();
    Mid_14fda0* GetSub();
};
class HitDamageAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual unsigned char v3(int, int);
    virtual void v4();
    virtual void v5();
    char pad1[0x1c - 4];
    void* p1c;
    Ref_14fda0* p20;
};
unsigned char HitDamageAction::v3(int, int) {
    if (p20) {
        Thing_14fda0* t = p20->d();
        if (t) {
            Mid_14fda0* m = p20->GetSub()->Touch();
            m->Draw(*(float*)((char*)p1c + 0x10) * t->x78, t->x4c, t->x48, t->x7c, 0, t->x91);
        }
    }
    return 0;
}
