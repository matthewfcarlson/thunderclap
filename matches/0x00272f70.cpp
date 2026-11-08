// Same code shape as 0x0026f130 (propagated; names are from that function)
class X_272f70 {
  public:
    virtual void f();
    virtual void g();
    int n;
};
// core::DriveThread's AddRef: the reference count under its IMutable base (+0xc; records.h CoreDriveThread)
class DriveThread_272f70 {
  public:
    virtual void vfunc_0();
    const void* vftableObject;
    int heap;
    X_272f70 x;
};
void DriveThread_272f70::vfunc_0() {
    X_272f70* p = &x;
    p->f();
    ++p->n;
    p->g();
}
