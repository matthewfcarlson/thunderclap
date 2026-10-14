// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_000c8630 @ 0x000c8630
struct Vec { float x,y,z; };
struct Key { unsigned int a,b; };
struct ResultWorker { void FUN_00059a50(Vec* out); };
struct Result { char pad[16]; ResultWorker* worker; };
struct Lookup { Result* FUN_00024280(unsigned int a,unsigned int b); };
struct Store { bool FUN_001dd7b0(Key* key); bool FUN_001dd5d0(Key* key,Vec* out); int FUN_001e3410(Key* key); };
struct Global { char pad[12]; Store* store; char pad2[16]; Lookup* lookup; };
extern Global* DAT_004dd700;
struct Entry { unsigned int unused; Vec value; Key key; char pad[32]; };
struct Object { char pad[0x2258]; Entry entries[1]; bool FUN_000c8630(int index,Vec* out); };
bool Object::FUN_000c8630(int index,Vec* out) {
 Entry* e=&entries[index];
 Key* key=&e->key;
 if (!(key->a|key->b)) { *out=e->value; return true; }
 Result* r=DAT_004dd700->lookup->FUN_00024280(key->a,key->b);
 if (r) { r->worker->FUN_00059a50(out); return true; }
 Store* store=DAT_004dd700->store;
 Vec v;
 if (store->FUN_001dd7b0(key) && store->FUN_001dd5d0(key,&v) && store->FUN_001e3410(key)>0) { *out=v; return true; }
 return false;
}