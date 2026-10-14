class Obj_6b050 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual Obj_6b050* get();
};
class CClearCollisionStun {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual int vfunc_12(Obj_6b050*);
    virtual void n();
};
int CClearCollisionStun::vfunc_12(Obj_6b050* p) {
    Obj_6b050* q = p->get();
    *(int*)((char*)q + 0x68) = 0;
    return 0;
}