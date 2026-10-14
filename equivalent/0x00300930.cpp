// STATUS: equivalent (tools/equiv.py level 3: 1215 inputs, branch coverage 10/10)
// FUN_00300930 @ 0x00300930
struct Item { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); };
struct Entry { char pad[12]; Item* first; Item* second; };
struct Input { char pad[40]; int count; int unknown; Entry* entries; char rest[61]; unsigned char enabled; };
struct Buffer { char* begin; char* end; char* capacity; };
struct Worker { void FUN_00302ed0(Item*,Item*,Buffer*); };
struct Receiver { void FUN_002f8020(Buffer*,int,int); };
void __cdecl FUN_0008d340(void*);
struct Owner { char pad[40]; Worker worker; char gap[63]; Receiver receiver; void target(Input*,int); };
void Owner::target(Input* input,int arg) {
 if (!input->enabled) return;
 Buffer buffer = {0,0,0};
 int offset=0;
 for(int i=0;i<input->count;++i) {
 Entry* entry = (Entry*)((char*)input->entries+offset);
 entry->first->v10();
 entry->second->v10();
 worker.FUN_00302ed0(entry->first,entry->second,&buffer);
 offset+=20;
 }
 if ((buffer.end-buffer.begin)/68 != 0) receiver.FUN_002f8020(&buffer,arg,0);
 if(buffer.begin) FUN_0008d340(buffer.begin);
}