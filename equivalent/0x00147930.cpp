// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 22/22)
// hulkfight::motion::GrappleAttachJointCondition::vfunc_6 @ 0x00147930
extern "C" { extern char DAT_00494b44; extern char DAT_00494b60; void* __cdecl FUN_00344e74(void*, int, void*, void*, int); }
struct Pair_147930 { unsigned first, second; };
struct Table_147930 { char pad[0x24]; Pair_147930* entries; };
struct Link_147930 { char pad[8]; Table_147930* table; };
struct Actor_147930 { char pad[0x120]; Link_147930* link; char pad2[0x210]; Actor_147930* previous; Actor_147930* attached; unsigned index; };
struct Context { Actor_147930* FUN_00059a30(); };
struct Input_147930 { Context* FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct GrappleAttachJointCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*, Input_147930*, void*);
 char pad[8]; unsigned mode; unsigned first, second;
};
bool GrappleAttachJointCondition::vfunc_6(void*, Input_147930* input, void*) {
 if (!FUN_00344e74(input,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 Actor_147930* actor = input->FUN_000592a0()->FUN_00059a30();
 Table_147930* table; unsigned index;
 if (actor->attached) { index=actor->index; table=actor->attached->link->table; }
 else { if (!actor->previous) return false; index=actor->previous->index; table=actor->link->table; }
 if (index==0xffff || !table) return false;
 Pair_147930 pair=table->entries[index];
 if (mode==0) return first==pair.first && second==pair.second;
 if (mode==1) return first!=pair.first || second!=pair.second;
 return false;
}
} }
