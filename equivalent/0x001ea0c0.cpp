// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 10/10)
// FUN_001ea0c0 @ 0x001ea0c0
// cl-flags: /GS
#include "decls/address.h"
#include "decls/data/game/global.h"
struct Key_1ea0c0 { unsigned int low, high; };
extern "C" int __cdecl sprintf(char*, const char*, ...);
struct Item_1ea0c0 { void FUN_001e9bf0(); };
struct Owner_1ea0c0 {
 Item_1ea0c0* FUN_001e98b0(Key_1ea0c0*);
 void FUN_001ea0c0(const char* text);
};
void Owner_1ea0c0::FUN_001ea0c0(const char* text) {
 if (DAT_0049caa0) {
 unsigned __int64 hash = FUN_002672f0(text,0,0);
 Key_1ea0c0 key;
 key.low = (unsigned int)hash; key.high = (unsigned int)(hash >> 32);
 Item_1ea0c0* item = FUN_001e98b0(&key);
 if (!item) {
 unsigned int length=0;
 while(text[length]) ++length;
 if(length < 31) {
 char buffer[64] = {0};
 sprintf(buffer,"%s_%s",text,text);
 hash=FUN_002672f0(text,0,0);
 key.low=(unsigned int)hash; key.high=(unsigned int)(hash >> 32);
 item=FUN_001e98b0(&key);
 }
 }
 if(item) item->FUN_001e9bf0();
 }
}
