// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 6/6)
// FUN_000f1e50 @ 0x000f1e50
extern "C" void* __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
extern int DAT_0049dba4; extern int DAT_0049f48c;
struct Context { void FUN_000fa0a0(); float FUN_000fad30(); };
struct Node { virtual void slot0(); virtual unsigned int type(); };
struct Vec3_f1e50 { float x,y,z; };
struct Object { void FUN_000f1bd0(Vec3_f1e50); };
struct FEThingsBase { struct ParseFunctor; };
struct Owner_f1e50 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33();
 virtual bool parseChildren(Context*, Node*, FEThingsBase::ParseFunctor*);
 virtual bool parseProperty(Context*, void*, void*, Node*);
 void FUN_000f1e50(Context*, void*, void*, Node*);
};
struct FEThingsBase::ParseFunctor {
 virtual void slot0();
 Owner_f1e50* owner;
 void (Owner_f1e50::*method)(Context*, void*, void*, Node*);
 void* arg;
 void* object;
};
void Owner_f1e50::FUN_000f1e50(Context* context, void* arg, void* object, Node* node) {
 Object* typed = (Object*)FUN_00344e74(object,0,&DAT_0049dba4,&DAT_0049f48c,0);
 if(node->type()==0xa137906dU) {
 Vec3_f1e50 v; v.x=0.0f; v.y=0.0f; v.z=context->FUN_000fad30()*0.01745329238474369f;
 typed->FUN_000f1bd0(v);
 } else {
 if(parseProperty(context,arg,object,node)) return;
 FEThingsBase::ParseFunctor f; f.owner=this; f.method=&Owner_f1e50::FUN_000f1e50; f.arg=arg; f.object=object;
 if(!parseChildren(context,node,&f)) context->FUN_000fa0a0();
 }
}