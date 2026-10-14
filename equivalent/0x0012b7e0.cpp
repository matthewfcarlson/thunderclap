// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// hulkfight::ai::ShotFailCountCondition::vfunc_6 @ 0x0012b7e0
extern char DAT_00494b44;
extern char DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct State_12b7e0 { char pad[0x1d1c]; int shotFailCount; };
struct AgentData { State_12b7e0* FUN_00059a30(); };
struct Agent_12b7e0 { AgentData* FUN_000592a0(); };
namespace hulkfight { namespace ai {
struct ShotFailCountCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*, Agent_12b7e0*, void*);
 char pad[8]; unsigned comparison; float threshold;
};
bool ShotFailCountCondition::vfunc_6(void*, Agent_12b7e0* agent, void*) {
 if (!FUN_00344e74(agent,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 int count = agent->FUN_000592a0()->FUN_00059a30()->shotFailCount;
 switch(comparison) {
 case 0: return (double)count < threshold;
 case 1: return (double)count <= threshold;
 case 2: return (double)count == threshold;
 case 3: return (double)count != threshold;
 case 4: return (double)count >= threshold;
 case 5: return (double)count > threshold;
 default: return false;
 }
}
}}
