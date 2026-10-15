class Ref {
  public:
    virtual void f0();
    virtual void release();
    int pad;
    int a;
    int b;
};
class CChaseCamera {
    char pad[0x350];
    Ref* volatile m;

  public:
    void vfunc_32(int a, int b);
};
void CChaseCamera::vfunc_32(int a, int b) {
    Ref* q = m;
    if (q && q->a == a && q->b == b) {
        Ref* r = m;
        if (r) {
            r->release();
            m = 0;
        }
    }
}