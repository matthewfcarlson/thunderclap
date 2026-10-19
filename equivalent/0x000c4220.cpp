// STATUS: equivalent (tools/equiv.py level 3: 19618 inputs, branch coverage 19/19)
// FUN_000c4220 @ 0x000c4220
// cl-flags: /GS
#include "decls/data/game/global.h"

struct State_c4220;
struct ThisNote_000c3ea0 {
    void FUN_000c3ea0();
};
struct Player_c4220 { void FUN_001b7310(const char*, int, int); };
struct Screen_c4220 { void FUN_001edf60(); void FUN_001ec480(const char*, const char*); };
struct State_c4220 {
 char pad0[8]; unsigned char finished; char pad9[7]; int mode; char pad14[0x28]; Screen_c4220* screen; char pad40[0x1b89]; char suffix[1];
 bool FUN_000c3900(const char*,int,int,int,int,int,int);
 void update(Player_c4220* player);
};
void State_c4220::update(Player_c4220* player) {
 struct Buffer { char text[64];  } buffer;
 switch((*(unsigned int*)&DAT_0049fb40)) {
 case 0: {
 const char* prefix="copyright-";
 unsigned int i;
 for(i=0;i<11;++i) buffer.text[i]=prefix[i];
 for(;i<64;++i) buffer.text[i]=0;
 const char* end=suffix;
 while(*end++) {}
 unsigned int count=end-suffix;
 char* dst=buffer.text;
 while(*dst) ++dst;
 const char* src=suffix;
 for(i=0;i<count/4;++i) {
 *(unsigned int*)dst=*(const unsigned int*)src;
 dst+=4; src+=4;
 }
 for(i=0;i<count%4;++i) *dst++=*src++;
 if(FUN_000c3900(buffer.text,5000,5000,0,0,0,0)) ++(*(unsigned int*)&DAT_0049fb40);
 break;
 }
 case 1: player->FUN_001b7310("dolby",1000,1); ++(*(unsigned int*)&DAT_0049fb40); break;
 case 2: player->FUN_001b7310("marvel",1000,1); ++(*(unsigned int*)&DAT_0049fb40); break;
 case 3: player->FUN_001b7310("radical",1000,1); ++(*(unsigned int*)&DAT_0049fb40); break;
 case 4: player->FUN_001b7310("sierra",1000,1); ++(*(unsigned int*)&DAT_0049fb40); break;
 case 5: player->FUN_001b7310("attract",1000,1); ++(*(unsigned int*)&DAT_0049fb40); break;
 case 6: finished=1; break;
 }
 if(finished) {
 ((ThisNote_000c3ea0*)(this))->FUN_000c3ea0();
 Screen_c4220* current=screen;
 (*(unsigned int*)&DAT_0049fb40)=0;
 if(current) { current->FUN_001edf60(); screen->FUN_001ec480("main","FE_screen_enter_start"); }
 mode=1;
 }
}
