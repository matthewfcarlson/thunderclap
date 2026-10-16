// STATUS: equivalent (tools/equiv.py level 3: 563 inputs, branch coverage 12/12)
// FUN_000894d0 @ 0x000894d0
#include "decls/address.h"
struct NameList_894d0 { const char** FUN_000b4f40(); };
struct Manager_894d0 { NameList_894d0* FUN_00086280(); };
struct World { char pad[0x54]; Manager_894d0* manager; };
extern unsigned DAT_004d9968;
// equiv-conv: __security_check_cookie ecx
extern "C" void __cdecl __security_check_cookie(unsigned);
extern "C" int __cdecl FUN_000964a0(char*, int, const char*, const char*);
extern "C" int __cdecl FUN_00267760(char*, int, const char*, const char*);
struct Entry_894d0 { unsigned low, high; char text[16]; };
struct Object { char pad[0x158]; Entry_894d0 entries[100]; void FUN_000894d0(); };
void Object::FUN_000894d0() {
 unsigned cookie=DAT_004d9968;
 const char** names=DAT_004dd700->manager->FUN_00086280()->FUN_000b4f40();
 const char** scan=names;
 int count=0;
 char buffer[64];
 for(int i=0;i<100;++i) {
  bool found=false;
  if(*scan) {
   do {
    FUN_000964a0(buffer,64,"%s_score",*scan);
    unsigned __int64 hash=FUN_0027b020(buffer);
    if(entries[i].low==(unsigned)hash && entries[i].high==(unsigned)(hash>>32)) {found=true;break;}
    ++scan;
   } while(*scan);
   if(!found) scan=names;
  }
  if(!found) { entries[i].low=0; entries[i].high=0; }
  else {
   if(i!=count) {
    entries[count].low=entries[i].low;
    entries[count].high=entries[i].high;
    FUN_00267760(entries[count].text,16,"%s",entries[i].text);
    entries[i].low=0;entries[i].high=0;
   }
   ++count;scan=names;
  }
 }
 __security_check_cookie(cookie);
}
