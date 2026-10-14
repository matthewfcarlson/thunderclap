// STATUS: equivalent (tools/equiv.py level 3: 1919 inputs, branch coverage 34/34)
// FUN_001f63a0 @ 0x001f63a0
struct Resource_1f63a0 { char pad[4]; void* handle; };
struct Entry_1f63a0 { unsigned int a,b; char pad08[0x18]; Resource_1f63a0* first; Resource_1f63a0* second; char pad28[0x48]; unsigned char active; char pad71[7]; int age; };
void __cdecl FUN_00249b40(void*);
struct Manager_1f63a0 { char pad[0xd4]; Entry_1f63a0* entries[148]; int count; Entry_1f63a0* selected; char pad32c[4]; int suspended; bool FUN_001f6250(Entry_1f63a0*); void FUN_001f4420(Entry_1f63a0*); void update(); };
void Manager_1f63a0::update() {
 if (suspended > 0) return;
 for (int i=0;i<count;++i) {
  if (entries[i] == selected) continue;
  if (entries[i]->active == 1) entries[i]->age=0;
  if (entries[i]->active == 0) {
   ++entries[i]->age;
   if (entries[i]->age > 5) {
    Resource_1f63a0* r=entries[i]->first;
    if(r && r->handle) FUN_00249b40(r->handle);
    r=entries[i]->second;
    if(r && r->handle) FUN_00249b40(r->handle);
    if(!FUN_001f6250(entries[i])) FUN_001f4420(entries[i]);
   }
  }
  entries[i]->active=0;
 }
 int i=0;
 while(i<count) {
  if ((entries[i]->a | entries[i]->b)==0) {
   for(int j=i;j<count-1;++j) {
    Entry_1f63a0* t=entries[j]; entries[j]=entries[j+1]; entries[j+1]=t;
   }
   --count;
  } else ++i;
 }
}