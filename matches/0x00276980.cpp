class Checker_276980 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual char check();
    void Finish(void*, int, int);
};
extern void __cdecl Parse(int, char*, char*, int*, int*);
extern void* __cdecl Allocate(int);
class InstanceDrive;
class Builder {
  public:
    Builder* make(InstanceDrive*, int, int);
};
class InstanceDrive {
  public:
    char pad[12];
    Checker_276980* checker;
    int field10;
    void vfunc_8(int p2, int p3);
};
void InstanceDrive::vfunc_8(int p2, int p3) {
    char local104[260];
    char local118[20];
    int local120 = 0;
    int local11c = 0;
    Parse(p2, local104, local118, &local11c, &local120);
    int value = local11c;
    if (checker->check() & 0x80)
        value = local120;
    Builder* b = (Builder*)Allocate(0x114);
    Builder* r;
    if (b)
        r = b->make(this, value, p3);
    else
        r = 0;
    checker->Finish(r, field10, 0);
}
