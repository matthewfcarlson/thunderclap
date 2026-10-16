// STATUS: equivalent (tools/equiv.py level 3: 373 inputs, branch coverage 11/12, incomplete)
// FUN_00257b30 @ 0x00257b30
#include "decls/data/engine/audio.h"

struct Text_257b30 { char data[12]; void FUN_0023fac0(); const char* FUN_0023fb00(); void FUN_00240060(); };
struct Entry_257b30 { char pad[16]; void* name; };
struct List_257b30 { char opaque; };
extern bool __cdecl FUN_0025abd0(void*, unsigned*);
extern Entry_257b30* __cdecl FUN_00247530(void*);
extern void* __cdecl FUN_002673a0(const char*, int);
extern bool __cdecl FUN_0025bce0(void*, Text_257b30*);
extern void __cdecl FUN_00257780(List_257b30*, Entry_257b30*, void**);
extern void __cdecl FUN_00247550(void*, Entry_257b30*);
struct Owner_257b30 { char pad[0x44]; List_257b30 list; bool target(void*); };
bool Owner_257b30::target(void* input) {
 unsigned count;
 if (!FUN_0025abd0(input, &count)) return false;
 for (unsigned i=0; i<count; ++i) {
  Entry_257b30* item = FUN_00247530(((char*)&DAT_004e7690));
  if (item) item->name = FUN_002673a0("MyBuss",0);
  Text_257b30 text;
  text.FUN_0023fac0();
  bool ok = FUN_0025bce0(input,&text);
  void** slot = &item->name;
  if (slot) *slot = FUN_002673a0(text.FUN_0023fb00(),0);
  text.FUN_00240060();
  if (!ok) { FUN_00247550(((char*)&DAT_004e7690),item); return false; }
  FUN_00257780(&list,item,slot);
 }
 return true;
}