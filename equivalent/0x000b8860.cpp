// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 12/12)
// FUN_000b8860 @ 0x000b8860
struct TypeInfo { unsigned int value; }; extern TypeInfo DAT_0049dba4, DAT_0049dbbc;
extern void* __cdecl FUN_000fc260(const char*);
struct Temp { char storage[36]; void FUN_000f7930(); void FUN_000f8500(unsigned int, int, int); void FUN_000f7960(); };
struct List { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void finish(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void add(Temp*, int, int); void FUN_000e36c0(); };
extern List* __cdecl FUN_00344e74(void*, int, TypeInfo*, TypeInfo*, int);
struct Entry { const char* key; unsigned int value; unsigned int unknown; }; extern Entry DAT_00406738[];
struct State { const char* FUN_0008a060(const char*); bool FUN_000893c0(); };
struct Target { char pad[52]; State* state; void FUN_000b8860(); };
void Target::FUN_000b8860() {
 List* list=FUN_00344e74(FUN_000fc260("story_recap_list"),0,&DAT_0049dba4,&DAT_0049dbbc,0);
 if (!list) return;
 list->FUN_000e36c0();
 Entry* entry=DAT_00406738;
 if(entry->key) {
 do {
 const char* result=state->FUN_0008a060(entry->key);
 if(!state->FUN_000893c0()) {
 if(!result) break;
 const char* text="complete"; int i;
 for(i=0;i<9;++i) if(result[i]!=text[i]) break;
 if(i!=9) break;
 }
 Temp temp; temp.FUN_000f7930(); temp.FUN_000f8500(entry->value,0,1); list->add(&temp,0,0); temp.FUN_000f7960();
 ++entry;
 } while(entry->key);
 }
 list->finish();
}
