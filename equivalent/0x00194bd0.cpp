// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 16/16)
// hulkfight::motion::AccuracyLatencyAction::vfunc_3 @ 0x00194bd0
struct Vec { float x,y,z; };
struct Position { void FUN_00059a50(Vec*); };
struct Entry { char pad[16]; Position* position; };
struct Link { char pad[8]; Entry* entry; int type; };
struct Actor { char pad[0x328]; Link* link; char pad2[0x1d60-0x32c]; unsigned idLow,idHigh; void FUN_00194720(Vec*); };
struct Object { Actor* FUN_00059a30(); };
struct Source { Object* FUN_000592a0(); };
struct Manager { Entry* FUN_00024280(unsigned,unsigned); };
struct Global { char pad[0x20]; Manager* manager; };
extern Global* DAT_004dd700;
namespace hulkfight { namespace motion {
struct AccuracyLatencyAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(unsigned, float); virtual void vfunc_4(); virtual void vfunc_5();
 char pad[0x1c]; Source* source; float time; float lastTime; float latency;
};
bool AccuracyLatencyAction::vfunc_3(unsigned unused, float t) {
 if (!source) return false;
 Object* obj=source->FUN_000592a0();
 Actor* actor=obj->FUN_00059a30();
 if (!obj || !actor) return false;
 lastTime=t;
 time=t+latency;
 Entry* entry;
 if (actor->link && actor->link->type==1) {
  entry=actor->link->entry;
  if (!entry) return true;
 } else {
  unsigned lo=actor->idLow, hi=actor->idHigh;
  if (!(lo|hi)) return true;
  entry=DAT_004dd700->manager->FUN_00024280(lo,hi);
  if (!entry) return true;
 }
 Vec v;
 entry->position->FUN_00059a50(&v);
 actor->FUN_00194720(&v);
 return true;
}
}}
