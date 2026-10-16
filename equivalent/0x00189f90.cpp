// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 8/8)
// FUN_00189f90 @ 0x00189f90
#include "decls/data/game/hulkfight/motion.h"

inline void* operator new(unsigned int, void* p) { return p; }
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
 void* p=FUN_0008d690(24);
 if(p) { params[0]=new(p) fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByNameTrack>; ((fight::ParamFloatConstRange<hulkfight::motion::PropSetStateByNameTrack>*)p)->callback=FUN_0017f720; } else params[0]=0;
 p=FUN_0008d690(24);
 if(p) { params[1]=new(p) fight::ParamIntConstRange<hulkfight::motion::PropSetStateByNameTrack>; ((fight::ParamIntConstRange<hulkfight::motion::PropSetStateByNameTrack>*)p)->callback=FUN_0017f740; } else params[1]=0;
 p=FUN_0008d690(24);
 if(p) { params[2]=new(p) fight::ParamName<hulkfight::motion::PropSetStateByNameTrack>; ((fight::ParamName<hulkfight::motion::PropSetStateByNameTrack>*)p)->callback=FUN_0017f750; } else params[2]=0;
 FUN_002347b0(&DAT_004e1470,params,3);
 }
 ++DAT_004e1474;
}