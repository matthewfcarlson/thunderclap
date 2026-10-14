// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 16/16)
// hulkfight::motion::AccuracyLatencyAction::vfunc_3 @ 0x00194bd0
struct Vec_194bd0 { float x,y,z; };
struct Position_194bd0 { void FUN_00059a50(Vec_194bd0*); };
struct Entry_194bd0 { char pad[16]; Position_194bd0* position; };
struct Link_194bd0 { char pad[8]; Entry_194bd0* entry; int type; };
struct Actor_194bd0 { char pad[0x328]; Link_194bd0* link; char pad2[0x1d60-0x32c]; unsigned idLow,idHigh; void FUN_00194720(Vec_194bd0*); };
struct Object { Actor_194bd0* FUN_00059a30(); };
struct Source_194bd0 { Object* FUN_000592a0(); };
struct Manager_194bd0 { Entry_194bd0* FUN_00024280(unsigned,unsigned); };
struct Global_194bd0 { char pad[0x20]; Manager_194bd0* manager; };
extern Global_194bd0* DAT_004dd700;
namespace hulkfight { namespace motion {
struct AccuracyLatencyAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(unsigned, float); virtual void vfunc_4(); virtual void vfunc_5();
 char pad[0x1c]; Source_194bd0* source; float time; float lastTime; float latency;
};
bool AccuracyLatencyAction::vfunc_3(unsigned unused, float t) {
 if (!source) return false;
 Object* obj=source->FUN_000592a0();
 Actor_194bd0* actor=obj->FUN_00059a30();
 if (!obj || !actor) return false;
 lastTime=t;
 time=t+latency;
 Entry_194bd0* entry;
 if (actor->link && actor->link->type==1) {
  entry=actor->link->entry;
  if (!entry) return true;
 } else {
  unsigned lo=actor->idLow, hi=actor->idHigh;
  if (!(lo|hi)) return true;
  entry=DAT_004dd700->manager->FUN_00024280(lo,hi);
  if (!entry) return true;
 }
 Vec_194bd0 v;
 entry->position->FUN_00059a50(&v);
 actor->FUN_00194720(&v);
 return true;
}
}}
