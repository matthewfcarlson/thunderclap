class CGrappleMotionTrailTrack;
extern void* FUN_0008d690(unsigned int);
struct Obj { char pad[0x104]; int value; };
extern Obj* FUN_0005a430(int);
struct Alloc { int invoke(CGrappleMotionTrailTrack*, int); };
class CGrappleMotionTrailTrack { public: int vfunc_12(int); };
int CGrappleMotionTrailTrack::vfunc_12(int arg) {
    CGrappleMotionTrailTrack* self = this;
    Alloc* p = (Alloc*)FUN_0008d690(0x28);
    if (p) {
        int v = FUN_0005a430(arg)->value;
        return p->invoke(self, v);
    }
    return 0;
}