// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001899a0..0x0018b4e0 (kind game, layer game, confidence low)
#include "tree_prelude.h"


// 0x00189f90 FUN_00189f90 (213 B): equivalent/0x00189f90.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: ?target@fn_fb83e8c8@@YAXXZ @82152ead97d7 @w47a99da963fd
#include "gen/owners.h"
#include "decls/data/game/hulkfight/motion.h"
namespace fn_fb83e8c8 {} using namespace fn_fb83e8c8;
namespace fn_fb83e8c8 {
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 8/8)
// FUN_00189f90 @ 0x00189f90


} // namespace fn_fb83e8c8
inline void* operator new(size_t, void* p) { return p; }
namespace fn_fb83e8c8 {

namespace hulkfight { namespace motion { class PropSetStateByNameTrack; } }
void FUN_0017f720(); void FUN_0017f740(); void FUN_0017f750();
void* __cdecl FUN_0008d690(unsigned int);
struct FUN_00234960 { FUN_00234960(const char* = "timeBegin"); virtual void slot(); char pad[12]; void (*callback)(); char tail[4]; };
struct FUN_002348e0 { FUN_002348e0(const char* = "attachmentIndex"); virtual void slot(); char pad[12]; void (*callback)(); char tail[4]; };
struct FUN_00234a90 { FUN_00234a90(const char* = "state"); virtual void slot(); char pad[12]; void (*callback)(); char tail[4]; };
namespace fight {
template<class T> struct ParamFloatConstRange : FUN_00234960 { virtual void slot(); };
template<class T> struct ParamIntConstRange : FUN_002348e0 { virtual void slot(); };
template<class T> struct ParamName : FUN_00234a90 { virtual void slot(); };
}
 
void __cdecl FUN_002347b0(void*,void**,int);
void target() {
 if (DAT_004e1474 == 0) {
 void* params[3];
 void* p=FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByNameTrack>));
 if(p) { params[0]=new(p) fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByNameTrack>; ((fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByNameTrack>*)p)->callback=FUN_0017f720; } else params[0]=0;
 p=FUN_0008d690((int)sizeof(fight::ParamIntConstRange<hulkfight::motion::PropSetStateByNameTrack>));
 if(p) { params[1]=new(p) fight::ParamIntConstRange<hulkfight::motion::PropSetStateByNameTrack>; ((fight::ParamIntConstRange<hulkfight::motion::PropSetStateByNameTrack>*)p)->callback=FUN_0017f740; } else params[1]=0;
 p=FUN_0008d690((int)sizeof(fight::ParamName<hulkfight::motion::PropSetStateByNameTrack>));
 if(p) { params[2]=new(p) fight::ParamName<hulkfight::motion::PropSetStateByNameTrack>; ((fight::ParamName<hulkfight::motion::PropSetStateByNameTrack>*)p)->callback=FUN_0017f750; } else params[2]=0;
 FUN_002347b0(&DAT_004e1470,params,3);
 }
 ++DAT_004e1474;
}
} // namespace fn_fb83e8c8

