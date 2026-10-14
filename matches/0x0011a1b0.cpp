struct TypeInfo_11a1b0 {
    int x;
};
extern TypeInfo_11a1b0 CFightParamsType_11a1b0;
extern TypeInfo_11a1b0 FightParamsType_11a1b0;
int __cdecl IsType(void*, int, TypeInfo_11a1b0*, TypeInfo_11a1b0*, int);
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
class Allocated_11a1b0 {
  public:
    int Init(MotionClosestWaypointTrack*, void*);
};
int MotionClosestWaypointTrack::vfunc_10(void* a, void* b, void* p) {
    int ok = IsType(p, 0, &FightParamsType_11a1b0, &CFightParamsType_11a1b0, 0);
    if (ok) {
        Allocated_11a1b0* x = (Allocated_11a1b0*)Allocate(0x68);
        if (x)
            return x->Init(this, p);
    }
    return 0;
}