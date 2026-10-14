// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000c6fe0 @ 0x000c6fe0
struct ResourceName_c6fe0 {
 unsigned int first, second;
 void FUN_0027af50();
 void FUN_0027af70(ResourceName_c6fe0* source);
};
void __cdecl FUN_00096e50(ResourceName_c6fe0* result, const char* name);
struct Lookup_c6fe0 { int FUN_00024280(unsigned int first, unsigned int second); };
struct Loader_c6fe0 { bool FUN_001dd7b0(ResourceName_c6fe0* name); };
struct Services_c6fe0 { char pad0[12]; Loader_c6fe0* loader; char pad1[16]; Lookup_c6fe0* lookup; };
extern Services_c6fe0* DAT_004dd700;
struct Entry_c6fe0 {
 int id;
 unsigned int state, count, flags;
 ResourceName_c6fe0 name;
 unsigned int extra;
 unsigned int reserved;
};
struct Manager_c6fe0 {
 char pad[0x60];
 Entry_c6fe0 entries[16];
 int FUN_000c6fe0(int id, const char* name);
};
int Manager_c6fe0::FUN_000c6fe0(int id, const char* name) {
 ResourceName_c6fe0 key;
 FUN_00096e50(&key, name);
 if (!DAT_004dd700->lookup->FUN_00024280(key.first, key.second) &&
     !DAT_004dd700->loader->FUN_001dd7b0(&key)) {
  key.FUN_0027af50();
  return -1;
 }
 for (int i = 0; i < 16; ++i) {
  if (entries[i].id == -1) {
   entries[i].id = id;
   entries[i].name.FUN_0027af70(&key);
   entries[i].state = 0;
   entries[i].count = 0;
   entries[i].flags = 0;
   entries[i].extra = 0;
   key.FUN_0027af50();
   return i;
  }
 }
 key.FUN_0027af50();
 return -1;
}
