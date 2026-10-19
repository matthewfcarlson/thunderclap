// STATUS: equivalent (tools/equiv.py level 3: 3063 inputs, branch coverage 21/21)
// FUN_000873a0 @ 0x000873a0
// cl-flags: /GS
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" int __cdecl sprintf(char *,const char *,...);
struct Gfx {
#define V(n) virtual void v##n();
V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89) V(90) V(91)
#undef V
};
struct State { unsigned current, previous; };
struct GameData { char pad0[16]; unsigned a,b,c,d; char pad1[24]; unsigned mode, extra; char pad2[8]; unsigned char active; };
struct Subsystem { void FUN_0008db60(int); void *FUN_000b4cf0(const char*); void FUN_00093c40(const char*); void FUN_00089810(const char*); void FUN_000895e0(void*); void FUN_00089300(const char*); void FUN_001ec3d0(); void FUN_000afe80(); void FUN_001eb4e0(); void FUN_001eb4d0(); void FUN_001b83c0(); };
struct Main {
unsigned unknown; State *state; GameData *data; char pad[12]; Subsystem *s18,*s1c,*s20; char pad2[12]; Subsystem *s30,*s34,*s38,*s3c;
void FUN_000865d0(); void FUN_00086630(); void FUN_00086790(); void FUN_000872a0(); void update();
};
void Main::update() {
char text[9][64];
while(state->current != state->previous) {
state->previous = state->current;
DAT_0052c2a8->v91();
switch(state->current) {
case 0: sprintf(text[0],"Entering %s state\n","GS_NONE"); break;
case 1:
if((*(unsigned char*)&DAT_004dd8d0)) {
if(((char*)&DAT_004dd890)[0]) {
FUN_000865d0();
void *item=s20->FUN_000b4cf0(((char*)&DAT_004dd890));
if(!item) { return; }
s3c->FUN_00093c40(((char*)&DAT_004dd890));
s38->FUN_00089810(((char*)&DAT_004dd890));
s38->FUN_000895e0(item);
s38->FUN_00089300("oneshot");
} else { FUN_000865d0(); s38->FUN_00089810("C00M01"); s38->FUN_00089300("story"); }
} else { FUN_000865d0(); sprintf(text[1],"Entering %s state\n","GS_FRONTEND"); }
break;
case 2: sprintf(text[2],"Entering %s state\n","GS_PREGAME"); FUN_00086630(); break;
case 3: sprintf(text[3],"Entering %s state\n","GS_PRESSSTART"); FUN_00086790(); break;
case 4: sprintf(text[4],"Entering %s state\n","GS_GAME"); s1c->FUN_0008db60(0); (*(unsigned char*)&DAT_004dd6f0)=0; data->active=0; data->mode=0x10000; data->extra=0; data->a=0; data->b=0; data->c=0; data->d=0; s30->FUN_001ec3d0(); break;
case 5: sprintf(text[5],"Entering %s state\n","GS_POSTGAME"); FUN_000872a0(); break;
case 6: sprintf(text[6],"Entering %s state\n","GS_PAUSE"); s18->FUN_000afe80(); s30->FUN_001eb4e0(); break;
case 7: sprintf(text[7],"Entering %s state\n","GS_FMV"); (*(unsigned char*)&DAT_004dd6f0)=1; s30->FUN_001eb4d0(); s34->FUN_001b83c0(); break;
case 8: sprintf(text[8],"Entering %s state\n","GS_QUIT"); break;
}
}
}
