extern "C" void _ReadWriteBarrier();
class Ref {
  public:
    virtual void A();
    virtual void B();
};
extern int vt;
class FaceMotionAction {
  public:
    int vptr;
    char pad[0x18];
    int* p;
    Ref* r;
    void Finish();
    void Run();
};
void FaceMotionAction::Run() {
    vptr = (int)&vt;
    _ReadWriteBarrier();
    if (r) {
        r->B();
        r = 0;
    }
    if (p)
        p = 0;
    Finish();
}