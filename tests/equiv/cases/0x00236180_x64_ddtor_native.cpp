// Same code shape as 0x00021840 (propagated; names are from that function)
#include "gen/fight.h"

// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<fight::FightNodeTimeCondition>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
// (x64eq) the native build instantiates the class, so clang emits the scalar deleting destructor in the 64-bit object
template class fight::ParamFloatConstRange<fight::FightNodeTimeCondition>;
#endif
