// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000c6fe0 @ 0x000c6fe0
struct ResourceName {
 unsigned int first, second;
 void FUN_0027af50();
 void FUN_0027af70(ResourceName* source);
};
void __cdecl FUN_00096e50(ResourceName* result, const char* name);
struct Lookup { int FUN_00024280(unsigned int first, unsigned int second); };
struct Loader { bool FUN_001dd7b0(ResourceName* name); };
struct Services { char pad0[12]; Loader* loader; char pad1[16]; Lookup* lookup; };
extern Services* DAT_004dd700;
struct Entry {
 int id;
 unsigned int state, count, flags;
 ResourceName name;
 unsigned int extra;
 unsigned int reserved;
};
struct Manager {
 char pad[0x60];
 Entry entries[16];
 int FUN_000c6fe0(int id, const char* name);
};
int Manager::FUN_000c6fe0(int id, const char* name) {
 ResourceName key;
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
