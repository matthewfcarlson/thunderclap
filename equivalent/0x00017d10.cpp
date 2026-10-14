// STATUS: equivalent (tools/equiv.py level 3: 3038 inputs, branch coverage 36/36)
// CTargetAction::vfunc_7 @ 0x00017d10
struct Entity;
struct Info_17d10 { char pad[0x74]; void* item; };
struct Entity { char pad[0x148]; void* owner; char pad2[0x20b0-0x14c]; int state; bool FUN_001d7450(); Info_17d10* FUN_001d72e0(); };
struct Target_17d10 { char pad[8]; Entity* entity; int kind; };
struct Actor_17d10 { char pad[0x328]; Target_17d10* target; unsigned char active; char pad2[7]; void* first; void* second; char pad3[0x1b48-0x33c]; unsigned char flag; Entity* FUN_00035ef0(int); void FUN_000393c0(); };
struct Intermediate_17d10 { Actor_17d10* FUN_00059a30(); };
struct Source_17d10 { Intermediate_17d10* FUN_000592a0(); };
struct Manager_17d10 { bool FUN_002edc00(void*); };
extern Manager_17d10* DAT_00554c14;
struct CTargetAction { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual bool vfunc_7(int); virtual void vfunc_8(); char pad[0x18]; Source_17d10* source; };
bool CTargetAction::vfunc_7(int) {
 Actor_17d10* actor = source->FUN_000592a0()->FUN_00059a30();
 if (actor->active) {
  Target_17d10* t = actor->target;
  if (!t) return true;
  int kind = t->kind;
  Entity* e = t->entity;
  bool clear = false;
  if (!kind || !e) clear = true;
  else if (kind == 5) {
   for (int i=0; i<8; ++i) { if (actor->FUN_00035ef0(i)==e) {clear=true; break;} }
   if (!clear) {
    void* owner=e->owner;
    if (owner && (owner==actor->first || owner==actor->second)) clear=true;
    else if (!e->FUN_001d7450()) clear=true;
    else { Info_17d10* info=e->FUN_001d72e0(); if (!info || !info->item) clear=true; else clear=!DAT_00554c14->FUN_002edc00(info->item); }
   }
  } else if (kind == 1) { clear = e==actor->first || e==actor->second || e->state==2; }
  if (!clear) return true;
  actor->FUN_000393c0();
  actor->active=0;
 }
 if (!actor->flag) actor->FUN_000393c0();
 return true;
}
