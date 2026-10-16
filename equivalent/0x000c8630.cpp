// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_000c8630 @ 0x000c8630
#include "decls/address.h"
struct Vec_c8630 { float x,y,z; };
struct Key_c8630 { unsigned int a,b; };
struct ResultWorker { void FUN_00059a50(Vec_c8630* out); };
struct Result_c8630 { char pad[16]; ResultWorker* worker; };
struct Lookup_c8630 { Result_c8630* FUN_00024280(unsigned int a,unsigned int b); };
struct Store { bool FUN_001dd7b0(Key_c8630* key); bool FUN_001dd5d0(Key_c8630* key,Vec_c8630* out); int FUN_001e3410(Key_c8630* key); };
struct World { char pad[12]; Store* store; char pad2[16]; Lookup_c8630* lookup; };
struct Entry_c8630 { unsigned int unused; Vec_c8630 value; Key_c8630 key; char pad[32]; };
struct Object { char pad[0x2258]; Entry_c8630 entries[1]; bool FUN_000c8630(int index,Vec_c8630* out); };
bool Object::FUN_000c8630(int index,Vec_c8630* out) {
 Entry_c8630* e=&entries[index];
 Key_c8630* key=&e->key;
 if (!(key->a|key->b)) { *out=e->value; return true; }
 Result_c8630* r=DAT_004dd700->lookup->FUN_00024280(key->a,key->b);
 if (r) { r->worker->FUN_00059a50(out); return true; }
 Store* store=DAT_004dd700->store;
 Vec_c8630 v;
 if (store->FUN_001dd7b0(key) && store->FUN_001dd5d0(key,&v) && store->FUN_001e3410(key)>0) { *out=v; return true; }
 return false;
}