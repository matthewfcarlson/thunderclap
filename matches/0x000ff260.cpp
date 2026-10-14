extern "C" void _ReadWriteBarrier();
class Obj_ff260 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
};
class CHand2HandAgent {
  public:
    char p0[8];
    int m8;
    char p1[0x58 - 12];
    Obj_ff260* obj;
    char p2[4];
    char m60;
    char p3[3];
    int m64;
    float m68;
    int m6c;
    float m70;
    float m74;
    char m78;
    char m79;
    char m7a;
    char m7b;
    char m7c;
    char m7d;
    char p4[0xf6];
    int x174;
    int x178;
    int x17c;
    int x180;
    int x184;
    int x188;
    int x18c;
    void vfunc_9();
};
void CHand2HandAgent::vfunc_9() {
    m8 = 0;
    obj->g();
    m60 = 0;
    m64 = 0;
    m6c = 0;
    m7a = 0;
    m7b = 0;
    m7c = 0;
    m78 = 0;
    m79 = 0;
    m68 = 999.0f;
    m70 = -1.0f;
    m7d = 1;
    m74 = 10.0f;
    _ReadWriteBarrier();
    x17c = 0;
    x178 = 0;
    x174 = 0;
    x18c = 0;
    x188 = 0;
    x184 = 0;
}