// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 4/4)
// FUN_001c9750 @ 0x001c9750
struct Details { char pad[0x118]; unsigned value1; unsigned value2; };
struct Texts { const char* FUN_000443b0(); const char* FUN_00044360(); };
struct Entry { char pad[0x11c]; Texts* texts; char pad2[0x1ca0-0x120]; Details* details; const char* FUN_00036d00(); };
struct Handle { void FUN_00059a50(); };
struct Manager { Entry* FUN_00059c10(unsigned); Handle* FUN_00059ba0(unsigned, void*); };
struct Globals { char pad[0x44]; Manager* manager; };
extern Globals* DAT_004dd700;
extern "C" void __cdecl FUN_00267830(char*, const char*, unsigned);
struct Object {
 unsigned size; unsigned arg; char pad0[8]; unsigned id; char name[0x40]; char text1[0x20]; char text2[0x20]; char pad1[4]; unsigned value1; unsigned value2; unsigned extra;
 Object* FUN_001c9750(unsigned, unsigned, unsigned);
};
Object* Object::FUN_001c9750(unsigned a, unsigned bytes, unsigned identifier) {
 unsigned char* p = reinterpret_cast<unsigned char*>(this);
 for (unsigned i=0;i<bytes;++i) p[i]=0;
 size=bytes; arg=a; id=identifier; name[0]=0; text1[0]=0;
 Entry* entry=DAT_004dd700->manager->FUN_00059c10(identifier);
 if(entry) {
 const char* s=entry->FUN_00036d00();
 FUN_00267830(name,s,0x40);
 s=entry->texts->FUN_000443b0();
 FUN_00267830(text1,s,0x20);
 s=entry->texts->FUN_00044360();
 FUN_00267830(text2,s,0x20);
 Handle* h=DAT_004dd700->manager->FUN_00059ba0(identifier,&extra);
 h->FUN_00059a50();
 value1=0; value2=0;
 Details* d=entry->details;
 if(d) { value1=d->value1; value2=d->value2; }
 }
 return this;
}
