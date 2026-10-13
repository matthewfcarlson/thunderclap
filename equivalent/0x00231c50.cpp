// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 18/18)
// fight::Node::vfunc_9 @ 0x00231c50
typedef unsigned __int64 Key;
extern unsigned int DAT_004e5b20, DAT_004e5b24, DAT_004e5b70, DAT_004e5b74, DAT_004e5ba0, DAT_004e5ba4;
struct Source {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12();
 virtual bool s13(); virtual Key s14(); virtual void s15(); virtual void s16(unsigned int,unsigned int); virtual void s17();
};
struct Context { char pad[0x28]; unsigned int value; };
struct ListA { char pad[16]; void FUN_00236ec0(); void FUN_00237160(unsigned int,unsigned int,unsigned int,Source*); };
struct ListB { char pad[16]; void FUN_00239e10(); void FUN_0023a020(unsigned int,unsigned int,unsigned int,Source*); };
namespace fight { struct Node {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual bool vfunc_9(Context*,Source*,unsigned int);
 char pad[0x14]; ListA a; ListB b;
 void FUN_00233c50(Context*,Source*,unsigned int);
 void FUN_002337c0(Context*,Source*,int);
}; }
bool fight::Node::vfunc_9(Context* context,Source* source,unsigned int arg) {
 if (!source->s13()) return false;
 Key key=source->s14();
 if ((unsigned int)key!=DAT_004e5b70 || (unsigned int)(key>>32)!=DAT_004e5b74) return false;
 source->s16(DAT_004e5b70,DAT_004e5b74);
 FUN_00233c50(context,source,arg);
 a.FUN_00236ec0();
 if(source->s13()) {
 key=source->s14();
 if((unsigned int)key==DAT_004e5b20 && (unsigned int)(key>>32)==DAT_004e5b24) a.FUN_00237160(DAT_004e5b20,DAT_004e5b24,context->value,source);
 }
 b.FUN_00239e10();
 if(source->s13()) {
 key=source->s14();
 if((unsigned int)key==DAT_004e5ba0 && (unsigned int)(key>>32)==DAT_004e5ba4) b.FUN_0023a020(DAT_004e5ba0,DAT_004e5ba4,context->value,source);
 }
 FUN_002337c0(context,source,-1);
 source->s17();
 return true;
}