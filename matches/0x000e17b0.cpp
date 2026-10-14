extern const float zero_e17b0;
extern const float minusone;
class FEDoAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
class FEDoAnimation;
class Helper_e17b0 {
  public:
    virtual void a();
    virtual void b(FEDoAnimation*);
    virtual void c();
    virtual void d();
    virtual void e(float);
    virtual float f();
    char pad[0x54];
    int done;
};
class FEDoAnimation : public FEDoAction {
  public:
    virtual void vfunc_1();
    virtual void vfunc_5();
    char p[0x30];
    Helper_e17b0* mHelper;
    int state;
    float value;
    float time;
    char q[0x0c];
    char flag;
    void update();
};
void FEDoAnimation::vfunc_1() {
    Helper_e17b0* h = mHelper;
    if (h) {
        if (time != zero_e17b0) {
            value = h->f();
            update();
        } else if (value > minusone) {
            h->e(value);
        }
        int d = (flag == 0);
        mHelper->done = d;
        mHelper->b(this);
        state = 2;
    }
}