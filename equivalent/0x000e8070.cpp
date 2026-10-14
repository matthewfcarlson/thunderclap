// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_000e8070 @ 0x000e8070
struct Input_e8070 { void FUN_000fa0a0(); void FUN_000fad30(); unsigned int FUN_000fad90(); };
struct Token_e8070 { virtual void slot0(); virtual unsigned int slot1(); };
unsigned int __cdecl FUN_0034483c();
struct Object;
struct FEThingsBase {
 struct ParseFunctor {
  virtual void invoke();
  FEThingsBase* owner;
  void (FEThingsBase::*function)(Input_e8070*, unsigned int, Object*, Token_e8070*);
  unsigned int context;
  Object* object;
 };
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33();
 virtual bool s34(Input_e8070*,Token_e8070*,ParseFunctor*);
 virtual void s35(); virtual void s36();
 virtual bool s37(Input_e8070*,Object*,Token_e8070*);
 virtual void s38();
 virtual bool s39(Input_e8070*,void*,Token_e8070*);
 void FUN_000e8070(Input_e8070*,unsigned int,Object*,Token_e8070*);
};
struct Object {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(unsigned int);
 virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49(); virtual void s50(); virtual void s51(); virtual void s52(); virtual void s53(unsigned int);
 char pad[0x850]; unsigned int stamp; char pad2[0x184]; unsigned int sub;
};
void FEThingsBase::FUN_000e8070(Input_e8070* input,unsigned int context,Object* object,Token_e8070* token) {
 unsigned int kind=token->slot1();
 if(kind==0x887d4b38) { object->s16(input->FUN_000fad90()); }
 else if(kind==0x16b6f665) { object->s53(input->FUN_000fad90()); }
 else if(kind==0x3752e43c) { input->FUN_000fad30(); object->stamp=FUN_0034483c(); }
 else if(!s39(input,&object->sub,token) && !s37(input,object,token)) {
 ParseFunctor functor; functor.owner=this; functor.function=&FEThingsBase::FUN_000e8070; functor.context=context; functor.object=object;
 if(!s34(input,token,&functor)) input->FUN_000fa0a0();
 }
}