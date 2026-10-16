// STATUS: equivalent (tools/equiv.py level 3: 438 inputs, branch coverage 23/26, incomplete)
// FUN_000adc60 @ 0x000adc60
#include "decls/data/game/global.h"

struct Entry_adc60 {
 char pad0[13];
 char disabled;
 char pad1[6];
 char name[256];
};
struct Owner_adc60 {
 char pad0[16];
 int count;
 Entry_adc60 **entries;
 char pad1[0x134-0x18];
 char selected[256];
 void FUN_000adc60();
};
void Owner_adc60::FUN_000adc60() {
 if (selected[0] != 0 || DAT_004de7a8[0] == 0) return;
 for (int i=0; i<count; ++i) {
  Entry_adc60 *entry=entries[i];
  if (!entry) continue;
  const char *a=entry->name;
  const char *b=DAT_004de7a8;
  bool match=false;
  if (a && *a) {
   while (*a == *b) {
    if (*a == 0) { match=true; break; }
    ++a; ++b;
   }
  }
  if (match) {
   entry->disabled=0;
   char *dest=selected;
   const char *src=DAT_004de7a8;
   char ch;
   do { ch=*src++; *dest++=ch; } while(ch);
  } else entry->disabled=1;
 }
}
