// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00146400 @ 0x00146400
namespace hulkfight { namespace motion { class HitEffectTrack; class SlowMotionTrack; class WorldDamageTrack; class WorldConeDamageTrack; class MotionBlurTrack; class MotionTrailStopTrack; } }
namespace fight {
template<class T> struct TrackFactoryCasterTemplate { virtual void cast(); };
}
extern void* __cdecl FUN_00236ac0(const char*, void*);
struct Registry_146400 { void FUN_002367c0(void*); };
bool __cdecl FUN_00146400(Registry_146400* registry) {
 fight::TrackFactoryCasterTemplate<hulkfight::motion::WorldDamageTrack> a;
 registry->FUN_002367c0(FUN_00236ac0("worldDamage", &a));
 fight::TrackFactoryCasterTemplate<hulkfight::motion::WorldConeDamageTrack> b;
 registry->FUN_002367c0(FUN_00236ac0("worldConeDamage", &b));
 fight::TrackFactoryCasterTemplate<hulkfight::motion::MotionTrailStopTrack> c;
 registry->FUN_002367c0(FUN_00236ac0("motionTrailStop", &c));
 fight::TrackFactoryCasterTemplate<hulkfight::motion::HitEffectTrack> d;
 registry->FUN_002367c0(FUN_00236ac0("hitEffect", &d));
 fight::TrackFactoryCasterTemplate<hulkfight::motion::SlowMotionTrack> e;
 registry->FUN_002367c0(FUN_00236ac0("effectSlowMotion", &e));
 fight::TrackFactoryCasterTemplate<hulkfight::motion::MotionBlurTrack> f;
 registry->FUN_002367c0(FUN_00236ac0("effectMotionBlur", &f));
 return true;
}