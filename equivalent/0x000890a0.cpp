// STATUS: equivalent (tools/equiv.py level 3: 397 inputs, branch coverage 6/6)
// FUN_000890a0 @ 0x000890a0
#include "decls/data/game/hulkfight.h"

extern unsigned int DAT_004d9968;
extern void __fastcall __security_check_cookie(unsigned int cookie);
struct Record_890a0 { unsigned int words[0x2fa]; };
struct Loader_890a0 { int FUN_0008ca70(unsigned int source, int index, Record_890a0* record, int size, void* scratch); };
extern void __cdecl FUN_000fb690(void* destination, const void* source, int size);
struct Manager_890a0 {
 char padding[0xac4];
 Loader_890a0* loader;
 Record_890a0* records;
 int FUN_000890a0(unsigned int source, int index);
};
int Manager_890a0::FUN_000890a0(unsigned int source, int index) {
 char scratch[128];
 unsigned int cookie=DAT_004d9968;
 Record_890a0* record = records + index;
 for (int i=0; i<0x2fa; ++i) record->words[i]=0;
 int result=loader->FUN_0008ca70(source,index,records+index,0xbe8,scratch);
 FUN_000fb690(&records[index].words[0xb68/4],scratch,0x40);
 if(index>=0 && result==0 && records[index].words[0] != (unsigned int)DAT_0049c294) result=12;
 __security_check_cookie(cookie);
 return result;
}