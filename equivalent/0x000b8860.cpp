// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 12/12)
// FUN_000b8860 @ 0x000b8860
#include "decls/data/game/global.h"

struct TypeInfo_b8860 { unsigned int value; }; extern TypeInfo_b8860 DAT_0049dba4, DAT_0049dbbc;
extern void* __cdecl FUN_000fc260(const char*);
struct Temp_b8860 { char storage[36]; void FUN_000f7930(); void FUN_000f8500(unsigned int, int, int); void FUN_000f7960(); };
struct List_b8860 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void finish(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void add(Temp_b8860*, int, int); void FUN_000e36c0(); };
extern List_b8860* __cdecl FUN_00344e74(void*, int, TypeInfo_b8860*, TypeInfo_b8860*, int);
struct Entry_b8860 { const char* key; unsigned int value; unsigned int unknown; }; 
struct State_b8860 { const char* FUN_0008a060(const char*); bool FUN_000893c0(); };
struct Target_b8860 { char pad[52]; State_b8860* state; void FUN_000b8860(); };
void Target_b8860::FUN_000b8860() {
 List_b8860* list=FUN_00344e74(FUN_000fc260("story_recap_list"),0,&DAT_0049dba4,&DAT_0049dbbc,0);
 if (!list) return;
 list->FUN_000e36c0();
 Entry_b8860* entry=((Entry_b8860*)&DAT_00406738);
 if(entry->key) {
 do {
 const char* result=state->FUN_0008a060(entry->key);
 if(!state->FUN_000893c0()) {
 if(!result) break;
 const char* text="complete"; int i;
 for(i=0;i<9;++i) if(result[i]!=text[i]) break;
 if(i!=9) break;
 }
 Temp_b8860 temp; temp.FUN_000f7930(); temp.FUN_000f8500(entry->value,0,1); list->add(&temp,0,0); temp.FUN_000f7960();
 ++entry;
 } while(entry->key);
 }
 list->finish();
}
