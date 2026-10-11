// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 28/28)
// FUN_001b7f40 @ 0x001b7f40
extern unsigned int DAT_004d9968;
extern void __fastcall __security_check_cookie(unsigned int);
struct Movie {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
 virtual void open(const char*, const char*, int, float);
 virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual void volume(float); virtual void slot11(); virtual int state();
};
struct Audio { void FUN_001eb870(); void FUN_001eb2a0(float,int); float FUN_001eba20(); };
struct Other { void FUN_000bb670(); };
struct Manager { Audio* FUN_000862e0(); Other* FUN_00086280(); };
struct Global { char pad[0x54]; Manager* manager; };
extern Global* DAT_004dd700;
extern unsigned char DAT_004dd839;
struct Resource { void FUN_002078d0(); void FUN_0008db60(int); };
extern int __cdecl FUN_00266da0(int);
extern int __cdecl sprintf(char*,const char*,...);
struct Target {
 char pad0[8]; unsigned char active; char pad9[3]; Movie* movie; char pad10[0x10c]; Resource* resource; Resource* resource2; char pad124[0xd]; unsigned char initialized;
 void FUN_001b77e0(); const char* FUN_001b73c0(const char*); void FUN_001b7970();
 void run(const char* name, unsigned char useName);
};
void Target::run(const char* name, unsigned char useName) {
 unsigned int cookie=DAT_004d9968;
 bool skip=false;
 if(movie) { int s=movie->state(); if(s==4 || s==3) skip=true; }
 if(!skip && movie) { int s=movie->state(); if(s==1 || s==2) skip=true; }
 if(!skip) {
 if(!initialized) {
 initialized=1;
 DAT_004dd700->manager->FUN_000862e0()->FUN_001eb870();
 for(int i=0;i<10;++i) DAT_004dd700->manager->FUN_000862e0()->FUN_001eb2a0(0.01f,0);
 }
 active=0;
 resource2->FUN_002078d0();
 int previous=FUN_00266da0(7);
 FUN_001b77e0();
 if(movie) {
 DAT_004dd700->manager->FUN_00086280()->FUN_000bb670();
 char path[256];
 sprintf(path,"%s\\%s.rmv",DAT_004dd839 ? "movies-pal":"movies",name);
 const char* result=FUN_001b73c0(name);
 float scale;
 if(!useName) result=(const char*)&scale;
 scale=DAT_004dd839 ? 1.2f : 1.0f;
 movie->open(path,result,0,scale);
 if(movie->state()==0) FUN_001b7970();
 else {
 float vol=DAT_004dd700->manager->FUN_000862e0()->FUN_001eba20()*0.01f;
 if(movie) movie->volume(vol);
 resource->FUN_0008db60(1);
 }
 }
 FUN_00266da0(previous);
 }
 __security_check_cookie(cookie);
}
