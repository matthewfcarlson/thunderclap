// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 30/30)
// fight::OpportunityAction::vfunc_5 @ 0x00237590
struct Result_237590;
struct Query_237590 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
 virtual Result_237590* s8(int, int);
};
struct Gate_237590 { bool FUN_00236f40(int, int, int); };
struct Result_237590 { void FUN_00231ad0(Result_237590**, int, int); };
extern void __cdecl FUN_00018840(Result_237590**, Result_237590*);
namespace fight {
struct OpportunityAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual bool vfunc_5(int, float);
 char pad[0x18]; int actor; char pad20[4]; float limit; float trigger;
 Query_237590* query; int mode; Gate_237590* gate; Result_237590** current; int context; int acquireEvent; int executeEvent; float elapsed; Result_237590* result;
};
bool OpportunityAction::vfunc_5(int event, float delta) {
 float a=limit, b=trigger;
 if(acquireEvent==event) {
  if(!result && (a<0.0f || elapsed<=a) && query) {
   if(gate->FUN_00236f40(actor,context,0)) {
    Result_237590* r=query->s8(context,0);
    if(r && r!=*current) FUN_00018840(&result,r);
   }
  }
  elapsed=delta+elapsed;
 }
 if(executeEvent==event && b>=0.0f && result && elapsed>=b) {
  result->FUN_00231ad0(current,context,mode);
  return false;
 }
 if(!(a<0.0f) && !(elapsed<=a) && !result) return false;
 return true;
}
}