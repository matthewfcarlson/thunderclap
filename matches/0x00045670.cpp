class C2 {
  public:
    int Get();
};
class C1 {
  public:
    C2* Sub();
};
class Mgr {
  public:
    char pad[0x54];
    C1* m54;
};
extern Mgr* gMgr;
extern const float kOne;
class Obj {
  public:
    char pad[0x314];
    float f314, f318, f31c;
    float Fn();
};
float Obj::Fn() {
    float r = kOne;
    Mgr* m = gMgr;
    if (m && m->m54) {
        C2* s = m->m54->Sub();
        if (s) {
            int k = m->m54->Sub()->Get();
            switch (k) {
            case 0:
                r = f314;
                break;
            case 1:
                r = f318;
                break;
            case 2:
                r = f31c;
                break;
            default:
                r = f318;
                break;
            }
        }
    }
    return r;
}
