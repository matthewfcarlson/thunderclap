// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CCollisionHeightCondition::vfunc_7 @ 0x0004c0c0
struct CollisionData {
 char pad0[0x2c]; float velocity;
 char pad30[0x2c]; float time;
 char pad60[4]; float acceleration;
};
struct Context {
 virtual void slot0(); virtual void slot1(); virtual void slot2();
 virtual CollisionData* slot3();
};
extern bool __cdecl FUN_00018960(float, float, float);
struct CCollisionHeightCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
 virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
 virtual bool vfunc_7(Context*);
 char pad4[8]; unsigned comparison; float threshold;
};
bool CCollisionHeightCondition::vfunc_7(Context* context) {
 CollisionData* data = context->slot3();
 if (!data) return false;
 float height = data->time * data->velocity * 0.5f - data->time * data->acceleration * data->time * 0.125f;
 switch (comparison) {
 case 0: return height < threshold;
 case 1: return height <= threshold;
 case 2: return FUN_00018960(height, threshold, 0.00001f);
 case 3: return !FUN_00018960(height, threshold, 0.00001f);
 case 4: return height >= threshold;
 case 5: return height > threshold;
 default: return false;
 }
}
