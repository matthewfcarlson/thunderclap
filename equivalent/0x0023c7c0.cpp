// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 12/12)
// fight::Bank::vfunc_9 @ 0x0023c7c0
typedef unsigned __int64 Id_23c7c0;
extern unsigned long DAT_004e5b20, DAT_004e5b24, DAT_004e5b30, DAT_004e5b34;
struct Object {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual bool s13(); virtual Id_23c7c0 s14(); virtual void s15(); virtual void s16(Id_23c7c0); virtual void s17();
};
struct Input_23c7c0 { char pad[0x28]; unsigned long value; };
struct List_23c7c0 { void FUN_00236ec0(); void FUN_00237160(Id_23c7c0, unsigned long, Object*); };
namespace fight { struct Bank {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual bool vfunc_9(Input_23c7c0*,Object*,unsigned long);
 char pad[0x14]; List_23c7c0 list;
 void FUN_00233c50(Input_23c7c0*,Object*,unsigned long);
 void FUN_002337c0(Input_23c7c0*,Object*,int);
}; }
bool fight::Bank::vfunc_9(Input_23c7c0* input, Object* object, unsigned long arg) {
 if (!object->s13()) return false;
 Id_23c7c0 id=object->s14();
 if ((unsigned long)id != DAT_004e5b30 || (unsigned long)(id>>32) != DAT_004e5b34) return false;
 object->s16(((Id_23c7c0)DAT_004e5b34<<32)|DAT_004e5b30);
 FUN_00233c50(input,object,arg);
 list.FUN_00236ec0();
 if(object->s13()) {
  id=object->s14();
  if((unsigned long)id==DAT_004e5b20 && (unsigned long)(id>>32)==DAT_004e5b24)
   list.FUN_00237160(((Id_23c7c0)DAT_004e5b24<<32)|DAT_004e5b20,input->value,object);
 }
 FUN_002337c0(input,object,-1);
 object->s17();
 return true;
}
