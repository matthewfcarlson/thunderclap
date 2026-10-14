// STATUS: equivalent (tools/equiv.py level 3: 294 inputs, branch coverage 22/22)
// FUN_00059f30 @ 0x00059f30
struct Resource { void FUN_0003b620(int); void FUN_00263e90(); };
struct Object { virtual void slot0(); virtual void slot1(); void FUN_00222b90(int); };
void __cdecl FUN_0008d330(void*);
void __cdecl FUN_0008d340(void*);
struct Item { char pad[16]; Resource* resource; int unused; Object* object; char tail[8]; void* FUN_00059f30(unsigned char flags); };
void* Item::FUN_00059f30(unsigned char flags) {
 if (flags & 2) {
  int* cookie = reinterpret_cast<int*>(this)-1;
  int count=*cookie;
  if(count>0) {
   Item* end=this+count;
   do {
    --end;
    if(end->resource) { end->resource->FUN_0003b620(0); end->resource->FUN_00263e90(); end->resource=0; }
    if(end->object) { end->object->FUN_00222b90(1); if(end->object) { end->object->slot1(); end->object=0; } }
   } while(--count);
  }
  if(flags & 1) FUN_0008d340(cookie);
  return cookie;
 }
 if(resource) { resource->FUN_0003b620(0); resource->FUN_00263e90(); resource=0; }
 if(object) { object->FUN_00222b90(1); if(object) { object->slot1(); object=0; } }
 if(flags & 1) FUN_0008d330(this);
 return this;
}