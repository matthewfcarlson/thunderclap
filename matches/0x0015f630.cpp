// Same code shape as 0x0011a1b0 (propagated; names are from that function)
struct TypeInfo_15f630 {
    int x;
};
extern TypeInfo_15f630 CFightParamsType_15f630;
extern TypeInfo_15f630 FightParamsType_15f630;
int __cdecl IsType(void*, int, TypeInfo_15f630*, TypeInfo_15f630*, int);
void* __cdecl Allocate(int);
class MotionClosestWaypointTrack {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual int vfunc_10(void*, void*, void*);
};
class Allocated_15f630 {
  public:
    int Init(MotionClosestWaypointTrack*, void*);
};
int MotionClosestWaypointTrack::vfunc_10(void* a, void* b, void* p) {
    int ok = IsType(p, 0, &FightParamsType_15f630, &CFightParamsType_15f630, 0);
    if (ok) {
        Allocated_15f630* x = (Allocated_15f630*)Allocate(0x68);
        if (x)
            return x->Init(this, p);
    }
    return 0;
}