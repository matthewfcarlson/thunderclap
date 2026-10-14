// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/9, incomplete)
// FEContainer::vfunc_48 @ 0x000e43c0
struct Result_e43c0 { unsigned a,b,c; };
extern "C" char* __cdecl _strchr(const char*,int);
void __cdecl FUN_000f6d10(const char*,Result_e43c0*);
unsigned __int64 __cdecl FUN_0027b020(const char*);
struct Dictionary { int FUN_0027b200(unsigned __int64); };
struct Data_e43c0 { char pad[8]; Dictionary* dictionary; void FUN_002848b0(int,int,Result_e43c0*); };
struct Child_e43c0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual Data_e43c0* v11();
};
struct FEContainer {
 virtual void vfunc_0();
 char pad[0x24]; Child_e43c0* children[8];
 void vfunc_48(const char*,Result_e43c0*);
};
void FEContainer::vfunc_48(const char* name,Result_e43c0* out) {
 if (_strchr(name,'.')) { FUN_000f6d10(name,out); return; }
 unsigned __int64 key=FUN_0027b020(name);
 for(int i=0;i<8;++i) {
  if(!children[i]) break;
  int index=children[i]->v11()->dictionary->FUN_0027b200(key);
  if(index!=0xffff) {
   children[i]->v11()->FUN_002848b0(index,0,out);
   return;
  }
 }
 out->a=0; out->b=0; out->c=0;
}