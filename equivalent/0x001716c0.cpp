// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// hulkfight::motion::JointRelativeAction::vfunc_5 @ 0x001716c0
struct Quaternion_1716c0 { float x,y,z,w; void FUN_0022b750(const Quaternion_1716c0*, const Quaternion_1716c0*, float); };
struct Vector { float x,y,z; };
struct Transform_1716c0 { void FUN_00221cf0(const Quaternion_1716c0*); void FUN_0022be40(const Vector*); };
struct Joint_1716c0 { char pad[0x18]; Transform_1716c0 transform; };
struct Actor_1716c0 { Actor_1716c0* FUN_000592a0(); void FUN_00059a30(); int FUN_00059a40(); };
struct Duration { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual float slot7(); };
namespace hulkfight { namespace motion {
struct JointRelativeAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual bool vfunc_5(int, float);
 char pad[0x18]; Duration* duration; Actor_1716c0* actor; Joint_1716c0* joint; Quaternion_1716c0 startRotation; Vector startPosition; Quaternion_1716c0 endRotation; Vector endPosition; float elapsed;
};
bool JointRelativeAction::vfunc_5(int mode, float delta) {
 if (mode != 0) return true;
 Actor_1716c0* a = actor->FUN_000592a0();
 a->FUN_00059a30();
 if (!a->FUN_00059a40()) return false;
 elapsed += delta;
 float total = duration->slot7();
 float fraction;
 if (!(total <= 0.0f) && !(elapsed > total)) fraction = elapsed / total;
 else fraction = 1.0f;
 Quaternion_1716c0 rotation = startRotation;
 rotation.FUN_0022b750(&rotation, &endRotation, fraction);
 joint->transform.FUN_00221cf0(&rotation);
 Vector position = startPosition;
 position.x = (endPosition.x - position.x) * fraction + position.x;
 position.y = (endPosition.y - position.y) * fraction + position.y;
 position.z = (endPosition.z - position.z) * fraction + position.z;
 joint->transform.FUN_0022be40(&position);
 return true;
}
}}
