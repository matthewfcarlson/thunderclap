// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 6/6)
// FEDoPushDialog::vfunc_1 @ 0x000f1290
struct DialogManager { void FUN_000be230(const char*,const char*,const char*,const char*,const char*,int,int,int); };
struct Owner { char pad[4]; DialogManager* manager; };
struct FEDoAction { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); };
struct FEDoPushDialog : FEDoAction { char pad04[12]; Owner* owner; char pad14[32]; char name[32]; char text[256]; char a[32]; char b[32]; char c[32]; int flags; virtual void vfunc_1(); };
void FEDoPushDialog::vfunc_1() {
 const char* sources[4] = {text,a,b,c};
 const char* values[4];
 for(int i=0;i<4;++i) { const char* s=sources[i]; values[i]=(s[0]=='-' && s[1]==0)?0:s; }
 owner->manager->FUN_000be230(name,values[0],values[1],values[2],values[3],flags,0,0);
}