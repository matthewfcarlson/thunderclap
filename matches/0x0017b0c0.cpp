class JointTrackerTrack { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual int vfunc_10(int, int, void*); };
extern int ParamsRTTI;
extern int CFightParamsRTTI;
extern int TypeCheck(void*, int, int*, int*, int);
extern void* Allocate(int);
class Obj { public: int Init(JointTrackerTrack*, void*); };
int JointTrackerTrack::vfunc_10(int a, int b, void* p) {
    if (TypeCheck(p, 0, &ParamsRTTI, &CFightParamsRTTI, 0)) {
        void* q = Allocate(0x78);
        if (q) return ((Obj*)q)->Init(this, p);
    }
    return 0;
}
