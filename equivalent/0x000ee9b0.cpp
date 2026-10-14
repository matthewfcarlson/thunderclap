// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 15/16, incomplete)
// FEContainer::vfunc_50 @ 0x000ee9b0
extern "C" char* __cdecl strchr(const char*, int);
extern void __cdecl FUN_000f6d70(const char*, unsigned int);
extern unsigned __int64 __cdecl FUN_0027b020(const char*);
extern void __cdecl FUN_000f69e0(void*, unsigned int);
struct Lookup_ee9b0 { unsigned int FUN_0027b200(unsigned __int64); };
struct Info_ee9b0 { char pad[8]; Lookup_ee9b0* lookup; };
struct Entry_ee9b0 { unsigned int unused; unsigned int key; void* value; };
struct Entries_ee9b0 { char pad[0x3c]; Entry_ee9b0* begin; Entry_ee9b0* end; };
struct Child_ee9b0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual Info_ee9b0* v11();
 char pad[0x40]; Entries_ee9b0* entries;
};
struct FEContainer { char pad[0x28]; Child_ee9b0* children[8]; void vfunc_50(const char* name, unsigned int arg); };
void FEContainer::vfunc_50(const char* name, unsigned int arg) {
 if (strchr(name, '.')) { FUN_000f6d70(name,arg); return; }
 unsigned __int64 hash=FUN_0027b020(name);
 unsigned int key=0xffff;
 int i=0;
 for (;i<8;++i) {
  Child_ee9b0* child=children[i];
  if (!child) break;
  Info_ee9b0* info=child->v11();
  key=info->lookup->FUN_0027b200(hash);
  if(key!=0xffff) break;
 }
 Entries_ee9b0* list=children[i]->entries;
 Entry_ee9b0* start=list->begin;
 unsigned char count=(unsigned char)(((int)((char*)list->end-(char*)start))/12);
 for(int n=0;n<count;++n) {
  Entry_ee9b0* entry=&start[(unsigned char)n];
  if(entry->key==key) {
   if(entry->value) FUN_000f69e0(entry->value,arg);
   return;
  }
 }
}
