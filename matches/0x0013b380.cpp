class Service_13b380 {
  public:
    Service_13b380* get();
    Service_13b380* check();
    void run(void*, int, float);
};
class AnimationLinkedAction {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void vfunc_4();
    virtual void e();
    char pad[0x1c];
    Service_13b380* m20;
    void* m24;
};
struct Obj_13b380 {
    virtual void a();
    virtual void b();
};
void AnimationLinkedAction::vfunc_4() {
    if (m24) {
        Service_13b380* x = m20->get();
        Service_13b380* y = x->check();
        if (y) {
            y->run(m24, 0, -1.0f);
            if (m24) {
                ((Obj_13b380*)m24)->b();
                m24 = 0;
            }
        }
    }
}