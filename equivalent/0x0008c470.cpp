// STATUS: equivalent (tools/equiv.py level 3: 2974 inputs, branch coverage 2/2)
// FUN_0008c470 @ 0x0008c470
struct Owner;
struct Pair { unsigned a,b; };
struct Interface {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
 virtual void attach(Owner*, unsigned);
 virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
 virtual unsigned open(Pair*, unsigned);
};
struct State { Interface* object; unsigned zero; char pad[0x64]; unsigned char flag1,flag2; char pad2[0x42]; unsigned result; unsigned a,b,c,d,e; };
extern State* __cdecl FUN_0008d6d0(unsigned);
extern unsigned __cdecl FUN_00266da0(unsigned);
extern Pair* __cdecl FUN_0008d690(unsigned);
extern void __cdecl thunk_FUN_00270f10(const char*,unsigned);
extern void __cdecl thunk_FUN_00271530(State*,const char*,unsigned,unsigned);
extern void __cdecl FUN_0008d330(Pair*);
struct Owner { unsigned unknown; unsigned parameter; State* state; void FUN_0008c470(unsigned); };
void Owner::FUN_0008c470(unsigned value) {
 parameter=value;
 state=FUN_0008d6d0(0xc8);
 unsigned saved=FUN_00266da0(1);
 Pair* pair=FUN_0008d690(8);
 pair->a=0; pair->b=0;
 FUN_00266da0(saved);
 state->zero=0;
 thunk_FUN_00270f10("U:",0);
 thunk_FUN_00271530(state,"U:",1,0);
 if(state->object) {
 state->object->attach(this,0);
 unsigned result=state->object->open(pair,parameter);
 state->result=result;
 state->flag1=0; state->flag2=0; state->zero=0;
 state->a=1; state->b=1; state->c=1; state->d=1; state->e=1;
 } else { state->object=0; }
 FUN_0008d330(pair);
}