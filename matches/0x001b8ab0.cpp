class Timer {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual int Get();
};
extern Timer* gTimer;
class CRenderManager_1b8ab0 {
    char pad0[0x18];

  public:
    char m18;
    char pad19[3];
    float m1c;
    float m20;
    char pad24[4];
    int m28;
    char pad2c[4];
    char m30;
    void Init();
};
void CRenderManager_1b8ab0::Init() {
    m30 = 1;
    m18 = 1;
    int t = gTimer->Get();
    m28 = 0;
    m20 = (float)t;
    m1c = (float)t;
}