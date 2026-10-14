// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000e7ad0 @ 0x000e7ad0
extern int DAT_0049dba4;
extern int DAT_0049f4c0;
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Reader { void FUN_000fa0a0(); bool FUN_000f9e90(); };
struct Item_e7ad0 { virtual void slot0(); virtual unsigned int type(); };
struct FEThingsBase {
 struct ParseFunctor {
  virtual void invoke();
  FEThingsBase* owner;
  void (FEThingsBase::*method)(Reader*,void*,void*,Item_e7ad0*);
  void* context;
  void* object;
 };
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33();
 virtual bool parse(Reader*,Item_e7ad0*,ParseFunctor*);
 virtual bool direct(Reader*,void*,void*,Item_e7ad0*);
 void FUN_000e7ad0(Reader*,void*,void*,Item_e7ad0*);
};
void FEThingsBase::FUN_000e7ad0(Reader* reader, void* context, void* object, Item_e7ad0* item) {
 FUN_00344e74(object,0,&DAT_0049dba4,&DAT_0049f4c0,0);
 if(item->type()==0x76744a71) { while(reader->FUN_000f9e90()) {} }
 else if(!direct(reader,context,object,item)) {
  ParseFunctor callback;
  callback.owner=this;
  callback.method=&FEThingsBase::FUN_000e7ad0;
  callback.context=context;
  callback.object=object;
  if(!parse(reader,item,&callback)) reader->FUN_000fa0a0();
 }
}
