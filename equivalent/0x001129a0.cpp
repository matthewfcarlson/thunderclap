// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 10/10)
// FUN_001129a0 @ 0x001129a0
#include "decls/data/game/unknown.h"

typedef void (__cdecl *Callback_1129a0)();
extern void __cdecl FUN_0010c4d0();
extern void __cdecl FUN_0010c4e0();
extern void __cdecl FUN_0010c4f0();
extern void __cdecl FUN_0010c510();
extern void* __cdecl FUN_0008d690(unsigned int);
extern void __cdecl FUN_002347b0(void*,void*,int);
inline void* operator new(unsigned int, void* p) { return p; }
namespace hulkfight { namespace ai { class HulkActionTrack; } }
struct Base_1129a0 {
 virtual void slot0();
 char padding[12];
 Callback_1129a0 callback;
 int tail;
 void FUN_00234960(const char*);
 void FUN_00234a90(const char*);
};
namespace fight {
 template<class T> struct ParamFloatConstRange : Base_1129a0 { virtual void slot0(); };
 template<class T> struct ParamName : Base_1129a0 { virtual void slot0(); };
}
void __cdecl FUN_001129a0() {
 if (DAT_004e0b7c == 0) {
  Base_1129a0* entries[4];
  Base_1129a0* p = (Base_1129a0*)FUN_0008d690(24);
  if (p) { p->FUN_00234960("timeBegin"); new(p) fight::ParamFloatConstRange<hulkfight::ai::HulkActionTrack>; p->callback=FUN_0010c4d0; }
  entries[0]=p;
  p=(Base_1129a0*)FUN_0008d690(24);
  if(p) { p->FUN_00234960("timeEnd"); new(p) fight::ParamFloatConstRange<hulkfight::ai::HulkActionTrack>; p->callback=FUN_0010c4e0; }
  entries[1]=p;
  p=(Base_1129a0*)FUN_0008d690(24);
  if(p) { p->FUN_00234a90("text"); new(p) fight::ParamName<hulkfight::ai::HulkActionTrack>; p->callback=FUN_0010c4f0; }
  entries[2]=p;
  p=(Base_1129a0*)FUN_0008d690(24);
  if(p) { p->FUN_00234960("value"); new(p) fight::ParamFloatConstRange<hulkfight::ai::HulkActionTrack>; p->callback=FUN_0010c510; }
  entries[3]=p;
  FUN_002347b0(&DAT_004e0b78,entries,4);
 }
 ++DAT_004e0b7c;
}
