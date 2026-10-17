// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// physics::CollisionCylinder::vfunc_13 @ 0x002f2fc0
namespace physics {
struct CallbackResult { void FUN_0022c3b0(void*, void*); };
struct Callback {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
 virtual CallbackResult* vfunc_4(void*, void*, void*);
};
struct Owner { char pad[0x18]; Callback* callback; };
struct CollisionCylinder {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
 virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
 virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
 virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
 char pad04[4]; void* field08; char pad0c[4]; Owner* owner; char pad14[5]; unsigned char dirty; char pad1a[0x2a]; char position[0x2c]; char pad70[4];
};
void CollisionCylinder::vfunc_13() {
 dirty = 1;
 CallbackResult* result = owner->callback->vfunc_4(field08, pad70, position);
 result->FUN_0022c3b0(pad70, position);
}
}