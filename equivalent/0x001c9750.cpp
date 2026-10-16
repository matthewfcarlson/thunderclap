// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 4/4)
// FUN_001c9750 @ 0x001c9750
#include "decls/address.h"
struct Details_1c9750 { char pad[0x118]; unsigned value1; unsigned value2; };
struct Texts_1c9750 { const char* FUN_000443b0(); const char* FUN_00044360(); };
struct Entry_1c9750 { char pad[0x11c]; Texts_1c9750* texts; char pad2[0x1ca0-0x120]; Details_1c9750* details; const char* FUN_00036d00(); };
struct Handle_1c9750 { void FUN_00059a50(); };
struct Manager_1c9750 { Entry_1c9750* FUN_00059c10(unsigned); Handle_1c9750* FUN_00059ba0(unsigned, void*); };
struct World { char pad[0x44]; Manager_1c9750* manager; };
extern "C" void __cdecl FUN_00267830(char*, const char*, unsigned);
struct Object {
 unsigned size; unsigned arg; char pad0[8]; unsigned id; char name[0x40]; char text1[0x20]; char text2[0x20]; char pad1[4]; unsigned value1; unsigned value2; unsigned extra;
 Object* FUN_001c9750(unsigned, unsigned, unsigned);
};
Object* Object::FUN_001c9750(unsigned a, unsigned bytes, unsigned identifier) {
 unsigned char* p = reinterpret_cast<unsigned char*>(this);
 for (unsigned i=0;i<bytes;++i) p[i]=0;
 size=bytes; arg=a; id=identifier; name[0]=0; text1[0]=0;
 Entry_1c9750* entry=DAT_004dd700->manager->FUN_00059c10(identifier);
 if(entry) {
 const char* s=entry->FUN_00036d00();
 FUN_00267830(name,s,0x40);
 s=entry->texts->FUN_000443b0();
 FUN_00267830(text1,s,0x20);
 s=entry->texts->FUN_00044360();
 FUN_00267830(text2,s,0x20);
 Handle_1c9750* h=DAT_004dd700->manager->FUN_00059ba0(identifier,&extra);
 h->FUN_00059a50();
 value1=0; value2=0;
 Details_1c9750* d=entry->details;
 if(d) { value1=d->value1; value2=d->value2; }
 }
 return this;
}
