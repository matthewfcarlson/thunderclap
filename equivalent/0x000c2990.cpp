// STATUS: equivalent (tools/equiv.py level 3: 12000 inputs, branch coverage 26/26; run with --inputs 12000)
// FUN_000c2990 @ 0x000c2990
struct Track { const char* FUN_00092330(); int FUN_00092310(); void FUN_00092360(int); };
struct Lookup { Track* FUN_00092ad0(int); };
struct Manager { void FUN_001d3600(const char*,int); };
struct Group { void FUN_001bdff0(const char*); };
struct Output { void FUN_001b7310(const char*,int,int); };
extern int DAT_0049dab8, DAT_0049db80;
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" Track* __cdecl FUN_00344e74(Track*,int,const void*,const void*,int);
extern "C" Manager* __cdecl FUN_001d4c90();
extern "C" int __cdecl FUN_000964a0(char*,int,const char*,...);
struct Target {
 char pad0[0x10]; int state; char pad14[0x38]; Lookup* lookup; char pad50[0xc]; Group* group; char pad60[0x1810]; unsigned char active; char pad1871[3]; int id;
 void FUN_000ba040(); void FUN_000c21b0(int);
 void run(Output* out);
};
void Target::run(Output* out) {
 unsigned int cookie = DAT_004d9968;
 Track* track = FUN_00344e74(lookup->FUN_00092ad0(id),0,&DAT_0049dab8,&DAT_0049db80,0);
 if (track) {
  if (!active) {
   char path[64];
   Manager* manager = FUN_001d4c90();
   FUN_000964a0(path,64,"frontend/lang/subtitles/timings/%s.lua",track->FUN_00092330());
   manager->FUN_001d3600(path,0);
   const char* names[8] = {"mog1","mog2","mog3","mog4","mog5","mog6","mog7","mog8"};
   for (int block=0; block<2; ++block) {
    bool matched=false;
    for (int index=0; index<4; ++index) {
     const char* name=track->FUN_00092330();
     const char* expected=names[block*4+index];
     int ch=0;
     while (ch<5 && name[ch]==expected[ch]) ++ch;
     if (ch==5) { matched=true; break; }
    }
    if (matched && group) group->FUN_001bdff0(block==0 ? "mog1-4" : "mog5-8");
   }
   out->FUN_001b7310(track->FUN_00092330(),1000,1);
   active=1;
   track->FUN_00092360(0);
   FUN_000ba040();
   FUN_000c21b0(id);
  } else {
   if (track->FUN_00092310()>1) out->FUN_001b7310(track->FUN_00092330(),1000,1);
   active=0;
   state=0;
  }
 }
 __security_check_cookie(cookie);
}