// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// hulkfight::motion::JointRelativeAction::vfunc_5 @ 0x001716c0
struct Quaternion { float x,y,z,w; void FUN_0022b750(const Quaternion*, const Quaternion*, float); };
struct Vector { float x,y,z; };
struct Transform { void FUN_00221cf0(const Quaternion*); void FUN_0022be40(const Vector*); };
struct Joint { char pad[0x18]; Transform transform; };
struct Actor { Actor* FUN_000592a0(); void FUN_00059a30(); int FUN_00059a40(); };
struct Duration { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual float slot7(); };
namespace hulkfight { namespace motion {
struct JointRelativeAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual bool vfunc_5(int, float);
 char pad[0x18]; Duration* duration; Actor* actor; Joint* joint; Quaternion startRotation; Vector startPosition; Quaternion endRotation; Vector endPosition; float elapsed;
};
bool JointRelativeAction::vfunc_5(int mode, float delta) {
 if (mode != 0) return true;
 Actor* a = actor->FUN_000592a0();
 a->FUN_00059a30();
 if (!a->FUN_00059a40()) return false;
 elapsed += delta;
 float total = duration->slot7();
 float fraction;
 if (!(total <= 0.0f) && !(elapsed > total)) fraction = elapsed / total;
 else fraction = 1.0f;
 Quaternion rotation = startRotation;
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
