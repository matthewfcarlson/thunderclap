// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// physics::CollisionWall::vfunc_13 @ 0x0030e870
namespace physics {
struct WallResult {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void *vfunc_4(unsigned int);
};
struct WallOwner { char pad[0x18]; WallResult *result; };
struct CollisionWall {
    char pad0[8]; unsigned int value; char pad1[4]; WallOwner *owner;
    char pad2[5]; unsigned char active; char pad3[0x1e];
    char bounds[0x10]; char output[4];
    void vfunc_13();
};
}
struct WallResponse { void FUN_0022c3b0(void *, void *); };
void physics::CollisionWall::vfunc_13() {
    active = 1;
    WallResponse *response = (WallResponse *)owner->result->vfunc_4(value);
    response->FUN_0022c3b0(output, bounds);
}