// STATUS: equivalent (tools/equiv.py level 3: 16411 inputs, branch coverage 8/8)
// FUN_000b51c0 @ 0x000b51c0
// cl-flags: /GS
// FUN_000b51c0 @ 0x000b51c0
#include "decls/data/game/global.h"

extern const char *__cdecl FUN_000f7120(int);
extern int __cdecl FUN_000964a0(char *, int, const char *, ...);
struct Resource_b51c0 {
 virtual void slot0(); virtual void release();
 virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13();
 virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17();
 virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21();
 virtual void slot22(); virtual unsigned char ready();
};
extern void __cdecl thunk_FUN_00271230(Resource_b51c0 **, const char *, int, int, int, int, int, int);
bool __cdecl FUN_000b51c0(int language) {
 int index=0;
 for (; index<6; ++index) { if (index==language) break; }
 if(index==6) index=0;
 char filename[64];
 FUN_000964a0(filename,64,(*(const char**)&DAT_0049f3b8),FUN_000f7120(index));
 Resource_b51c0 *resource;
 thunk_FUN_00271230(&resource,filename,0,0,1,0,1,1);
 bool result=resource->ready()!=0;
 resource->release();
 return result;
}
