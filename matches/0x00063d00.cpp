// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/fight.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<CWeaponCollisionTrack>::~ParamFloatConstRange() {}
