// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 7/8, incomplete)
// physics::CollisionAABB::vfunc_11 @ 0x00312ab0
namespace physics {
struct CollisionVolume {
  virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2();
  virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
  virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8();
  virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(void*);
  virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
};
struct Children { CollisionVolume** begin; CollisionVolume** end; };
struct CollisionAABB : CollisionVolume {
  char pad[0x10];
  Children* children;
  void vfunc_11(void* argument);
};
void CollisionAABB::vfunc_11(void* argument) {
  if (children) {
    for (unsigned int i = 0; i < (unsigned int)(children->end - children->begin); ++i)
      children->begin[i]->vfunc_11(argument);
  }
  vfunc_8();
}
}