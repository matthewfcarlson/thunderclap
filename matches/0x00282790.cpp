class Base { public: virtual void Dummy(); Base(); };
class CMotionTrail : public Base {
public:
    virtual void V();
    char p0[0x0c];
    int x;
    char p1[0x2c];
    int a;
    int b;
    char p2[0x1c];
    void* p;
    char p3[0x0c];
    void* q;
    void* r;
    CMotionTrail();
};
extern void* __cdecl Alloc(unsigned int);
void CMotionTrail::V() {}
CMotionTrail::CMotionTrail() {
    a = 0;
    b = 0;
    x = 1;
    p = Alloc(8000);
    q = Alloc(0x18);
    r = Alloc(0x48);
}
