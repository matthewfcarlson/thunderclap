// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 26/26)
// FUN_000c0e40 @ 0x000c0e40
typedef void (*Callback)();
#define CB(a) extern void FUN_##a();
CB(000b43e0) CB(000b45a0) CB(000b45b0) CB(000b45d0) CB(000b47b0) CB(000b4850) CB(000b4b60) CB(000b4e30) CB(000b5490) CB(000b54d0) CB(000b5530) CB(000b5590) CB(000b5670) CB(000b5710) CB(000b5790) CB(000b57d0) CB(000b5810) CB(000b89c0) CB(000bb5c0) CB(000bc1e0) CB(000bc230) CB(000bc750) CB(000bf450)
extern unsigned char DAT_004ddbd0; extern unsigned DAT_004ddc08,DAT_004ddc0c;
extern char DAT_0048e100[],DAT_0048e0f0[],DAT_0048e134[],DAT_0049cad8[];
void* __cdecl FUN_0008d690(unsigned);
inline void* __cdecl operator new(unsigned,void* p) { return p; }
unsigned char __cdecl FUN_001d04d0(const void*);
struct CFEManager;
struct Binding { virtual void slot(); char pad[12]; unsigned char argumentType; char pad2[7]; unsigned char resultType; char pad3[3]; Callback callback; CFEManager* owner; void FUN_001d0480(const char*,int); Binding* FUN_000c0030(const char*,CFEManager*,Callback); Binding* FUN_000c0200(const char*,CFEManager*,Callback); };
template<class C,class R,class A> struct Method1: Binding { virtual void slot(); };
template<class C,class R,class A> struct Closure1: Method1<C,R,A> { virtual void slot(); };
struct Registry { void FUN_001d3b70(const char*,Binding*); void FUN_000c06e0(const char*,CFEManager*,Callback); void FUN_000c0740(const char*,CFEManager*,Callback); void FUN_000bfc50(const char*,Callback); void FUN_000bfcc0(const char*,Callback); void FUN_000c0850(const char*,CFEManager*,Callback); void FUN_000c08b0(const char*,CFEManager*,Callback); void FUN_000c0960(const char*,CFEManager*,Callback); };
Registry* FUN_001d4c90();
struct Item { unsigned words[2]; void FUN_0027af00(); }; struct Record { Item items[4]; unsigned tail[2]; };
struct CFEManager { virtual void slot(); unsigned f4; unsigned char f8; char p9[7]; unsigned f10,f14,f18,f1c,f20,f24; unsigned char f28; char p29[3]; unsigned f2c,f30,f34,f38,f3c,f40,f44,f48,f4c,f50,f54,f58,f5c,f60,f64,f68; unsigned arrayA[128],arrayB[128]; unsigned f46c; Record records[128]; unsigned char f1870; char p1871[3]; unsigned f1874; unsigned char f1878; char p1879[3]; unsigned f187c,f1880; char p1884[0x180]; unsigned char f1a04,f1a05,f1a06; char p1a07[0x1c1]; unsigned char f1bc8,f1bc9; char p1bca[2]; unsigned char f1bcc; char p1bcd[0x3f]; unsigned char f1c0c; char p1c0d[0x3f]; unsigned char f1c4c; char p1c4d[0x3f]; unsigned char f1c8c; char p1c8d[0x1f]; unsigned char f1cac; char p1cad[0x3f]; int f1cec,f1cf0; unsigned f1cf4,f1cf8,f1cfc; unsigned char f1d00; char p1d01[3]; unsigned f1d04,f1d08,f1d0c,f1d10,f1d14,f1d18,f1d1c; float f1d20; unsigned f1d24,f1d28,f1d2c,f1d30,f1d34; CFEManager(); };
#define MAKE(T,N,F,D) b=(Binding*)FUN_0008d690(36); if(b) { b->FUN_001d0480(N,1); new(b) Method1<CFEManager,void,T>; b->callback=FUN_##F; b->resultType=FUN_001d04d0(DAT_0048e100); b->argumentType=FUN_001d04d0(D); new(b) Closure1<CFEManager,void,T>; b->owner=this; } r->FUN_001d3b70(N,b)
#define SIMPLE(F,N,C) b=(Binding*)FUN_0008d690(36); if(b) b=b->F(N,this,FUN_##C); r->FUN_001d3b70(N,b)
CFEManager::CFEManager() {
for(int i=0;i<128;++i) { records[i].items[0].FUN_0027af00(); records[i].items[1].FUN_0027af00(); records[i].items[2].FUN_0027af00(); records[i].items[3].FUN_0027af00(); }
f1cec=f1cf0=-1; f1d04=f1d08=f1d0c=255;
f10=f14=f18=f1c=0; f8=0; f24=f60=f68=f30=f34=f38=f3c=f48=f54=0; f28=0; f2c=f58=f4c=f5c=f1880=0; f1a06=f1bc8=f1a04=f1a05=f1c8c=f1cac=0; f1cf4=f1cfc=0; f1d00=0; f1d10=f1d14=f1d18=128; f1d1c=0; f1d20=1.0f; f1d24=f1d28=f1d2c=f1d30=f1d34=0;
for(i=0;i<128;++i) arrayA[i]=0; for(i=0;i<128;++i) arrayB[i]=0; for(i=0;i<128;++i) { for(int j=0;j<4;++j) records[i].items[j].words[0]=records[i].items[j].words[1]=0; records[i].tail[0]=records[i].tail[1]=0; }
Registry* r=FUN_001d4c90(); if(!r) return; Binding* b;
MAKE(char*,"fe_SetMissionFailureHint",000b89c0,DAT_0049cad8);
r->FUN_000c06e0("SetMissionInfo",this,FUN_000b4e30); r->FUN_000c0740("fe_StartNextMission",this,FUN_000bc750); r->FUN_000bfc50("fe_changeScreen",FUN_000b45a0); r->FUN_000bfcc0("fe_backScreen",FUN_000b45b0); r->FUN_000bfc50("fe_loadScript",FUN_000b45d0);
MAKE(const char*,"fe_doScreen",000bc1e0,DAT_0048e0f0);
SIMPLE(FUN_000c0030,"fe_fullscreenMessage",000b47b0);
r->FUN_000c0850("fe_fullscreenMessageEx",this,FUN_000b4850); r->FUN_000c08b0("fe_fullscreenQuestion",this,FUN_000bc230); r->FUN_000c0740("fe_unlockStory",this,FUN_000bb5c0);
SIMPLE(FUN_000c0200,"fe_exitSim",000bf450); r->FUN_000c0960("fe_GetSelectedMove",this,FUN_000b43e0);
MAKE(const char*,"fe_SetupSMSuccessName",000b5490,DAT_0048e0f0);
r->FUN_000c0850("fe_SetupSMSuccessResult",this,FUN_000b54d0); r->FUN_000c0850("fe_SetupSMSuccessRecord",this,FUN_000b5530);
MAKE(int,"fe_SetupSMSuccessRanking",000b5590,DAT_0048e134);
MAKE(int,"fe_SetupSMSuccessSmashPointsAward",000b5670,DAT_0048e134);
r->FUN_000c0850("fe_SetupSMSuccessNewRecord",this,FUN_000b5710);
MAKE(const char*,"fe_SetupSMFailName",000b5790,DAT_0048e0f0);
MAKE(const char*,"fe_SetupSMFailHint",000b57d0,DAT_0048e0f0);
r->FUN_000c0850("fe_SetupSMFailRecord",this,FUN_000b5810);
SIMPLE(FUN_000c0030,"AddValidMission",000b4b60);
if(!DAT_004ddbd0) { DAT_004ddc08=0xffb72025; DAT_004ddc0c=0xff65b742; DAT_004ddbd0=1; }
f1874=0x248; f187c=0x261; f1870=f1878=f1bc9=f1bcc=f1c0c=f1c4c=0;
}
