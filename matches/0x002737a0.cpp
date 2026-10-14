class V {
  public:
    virtual void f0();
    virtual void f1();
};
struct Obj_2737a0 {
    char pad[4];
    V sub;
    char pad2[12];
    int count;
};
class Q_2737a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int);
};
class DriveCompletionRequest {
  public:
    char pad[12];
    Obj_2737a0* p;
    Q_2737a0* q;
    int arg;
    void vfunc_7();
};
void DriveCompletionRequest::vfunc_7() {
    p->sub.f0();
    --p->count;
    p->sub.f1();
    q->f3(arg);
}
