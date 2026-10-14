class Obj_2748a0 {
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual int call19(void*, int);
    int* Fetch();
};
class Sub_2748a0 {
  public:
    virtual void a();
    virtual void b();
};
struct Drive {
    char p0[4];
    Sub_2748a0 sub;
    char p1[4];
    Obj_2748a0* obj;
    char p2[8];
    int result;
    char p3[4];
};
class DriveFindNextRequest {
  public:
    virtual void a();
    virtual int vfunc_1();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    char p[4];
    Drive* drive;
    int arg;
};
int DriveFindNextRequest::vfunc_1() {
    Obj_2748a0* o = drive->obj;
    int r = o->call19((char*)drive + 0x1c, arg);
    int v = (int)o->Fetch();
    drive->sub.a();
    drive->result = v;
    drive->sub.b();
    return r;
}