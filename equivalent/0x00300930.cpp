// STATUS: equivalent (tools/equiv.py level 3: 1215 inputs, branch coverage 10/10)
// FUN_00300930 @ 0x00300930
struct Item_300930 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); };
struct Entry_300930 { char pad[12]; Item_300930* first; Item_300930* second; };
struct Input_300930 { char pad[40]; int count; int unknown; Entry_300930* entries; char rest[61]; unsigned char enabled; };
struct Buffer_300930 { char* begin; char* end; char* capacity; };
struct Worker_300930 { void FUN_00302ed0(Item_300930*,Item_300930*,Buffer_300930*); };
struct Receiver_300930 { void FUN_002f8020(Buffer_300930*,int,int); };
void __cdecl FUN_0008d340(void*);
struct Owner_300930 { char pad[40]; Worker_300930 worker; char gap[63]; Receiver_300930 receiver; void target(Input_300930*,int); };
void Owner_300930::target(Input_300930* input,int arg) {
 if (!input->enabled) return;
 Buffer_300930 buffer = {0,0,0};
 int offset=0;
 for(int i=0;i<input->count;++i) {
 Entry_300930* entry = (Entry_300930*)((char*)input->entries+offset);
 entry->first->v10();
 entry->second->v10();
 worker.FUN_00302ed0(entry->first,entry->second,&buffer);
 offset+=20;
 }
 if ((buffer.end-buffer.begin)/68 != 0) receiver.FUN_002f8020(&buffer,arg,0);
 if(buffer.begin) FUN_0008d340(buffer.begin);
}