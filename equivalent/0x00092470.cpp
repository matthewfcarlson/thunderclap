// STATUS: equivalent (tools/equiv.py level 3: 4486 inputs, branch coverage 15/16, incomplete)
// FUN_00092470 @ 0x00092470
// cl-flags: /GS
#include "decls/address.h"
extern "C" int __cdecl sprintf(char *, const char *, ...);
struct Item_92470 { char pad[8]; unsigned char state; };
struct Observer_92470 { void FUN_000c2c10(int); };
struct Table_92470 {
 Item_92470 *items[866];
 Observer_92470 *observer;
 bool FUN_00092470(int first, int last, const char *format, unsigned __int64 key, unsigned char state);
};
bool Table_92470::FUN_00092470(int first, int last, const char *format, unsigned __int64 key, unsigned char state) {
 char buffer[256];
 bool found=false;
 for (int n=0; first+n <= last; ++n) {
  sprintf(buffer, format, n);
  if (FUN_0027b020(buffer) == key) {
   int index=first+n-1;
   if(index>=first && index<=last) {
    Item_92470 *item=items[index];
    if(item->state!=state) {
     item->state=state;
     if(observer) observer->FUN_000c2c10(index);
    }
   }
   found=true;
   break;
  }
 }
 return found;
}