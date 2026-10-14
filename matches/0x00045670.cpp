class C2_45670 {
  public:
    int Get();
};
class C1_45670 {
  public:
    C2_45670* Sub();
};
class Mgr_45670 {
  public:
    char pad[0x54];
    C1_45670* m54;
};
extern Mgr_45670* gMgr_45670;
extern const float kOne;
class Obj_45670 {
  public:
    char pad[0x314];
    float f314, f318, f31c;
    float Fn();
};
float Obj_45670::Fn() {
    float r = kOne;
    Mgr_45670* m = gMgr_45670;
    if (m && m->m54) {
        C2_45670* s = m->m54->Sub();
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
