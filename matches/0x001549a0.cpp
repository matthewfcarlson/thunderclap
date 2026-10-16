struct TrackFactoryCaster {
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
struct HitReactionFloatTrackCaster : TrackFactoryCaster {
    virtual bool vfunc_0(void*);
};
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern int a, b;
bool HitReactionFloatTrackCaster::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &a, &b, 0) != 0;
}