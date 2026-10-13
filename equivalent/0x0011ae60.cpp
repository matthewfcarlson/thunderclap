// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0011ae60 @ 0x0011ae60
namespace hulkfight { namespace ai { class MotionFleeTrack; class MotionStopTrack; class MotionFacingTrack; class MotionBoostTrack; class MotionLocatorTrack; class MotionTargetTrack; class MotionChaseTrack; class MotionClosestWaypointTrack; } }
namespace fight { template<class T> struct TrackFactoryCasterTemplate { virtual void create(); }; }
extern void* __cdecl FUN_00236ac0(const char*, void*);
struct Registry { void FUN_002367c0(void*); };
void __cdecl FUN_0011ae60(Registry* registry) {
 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionStopTrack> stop;
 registry->FUN_002367c0(FUN_00236ac0("motionStop", &stop));
 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionFacingTrack> facing;
 registry->FUN_002367c0(FUN_00236ac0("motionFacing", &facing));
 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionTargetTrack> target;
 registry->FUN_002367c0(FUN_00236ac0("motionTarget", &target));
 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionChaseTrack> chase;
 registry->FUN_002367c0(FUN_00236ac0("motionChase", &chase));
 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionBoostTrack> boost;
 registry->FUN_002367c0(FUN_00236ac0("motionBoost", &boost));
 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionLocatorTrack> locator;
 registry->FUN_002367c0(FUN_00236ac0("motionLocator", &locator));
 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionClosestWaypointTrack> waypoint;
 registry->FUN_002367c0(FUN_00236ac0("motionClosestWaypoint", &waypoint));
 fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionFleeTrack> flee;
 registry->FUN_002367c0(FUN_00236ac0("motionFlee", &flee));
}
