// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001be060 @ 0x001be060
#include "decls/data/game/unknown.h"

struct Subtitle { char pad[0x38]; struct Sink* sink; char pad2[0x0c]; int key; void FUN_001be060(); }; struct Sink { void FUN_000f7110(); void FUN_000f7a80(char*); }; extern int __cdecl FUN_000f7120(int); extern void __cdecl FUN_000964a0(char*,int,const char*,int);  extern int DAT_004d9968; extern void __fastcall __security_check_cookie(int); void Subtitle::FUN_001be060() { int cookie=DAT_004d9968; int value = FUN_000f7120(key); if (value && sink) { sink->FUN_000f7110(); char text[64]; FUN_000964a0(text,64,(*(const char**)&DAT_004c4c6c),value); sink->FUN_000f7a80(text); } __security_check_cookie(cookie); }