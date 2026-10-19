// STATUS: equivalent (tools/equiv.py level 3: 13083 inputs, branch coverage 2/2)
// FUN_001db110 @ 0x001db110
// cl-flags: /GS
struct Options { unsigned int first; char rest[0x2b4]; void FUN_001d1630(); };
struct Manager_1db110 { void FUN_001d3b00(char*, Options); };
extern Manager_1db110* __cdecl FUN_001d4c90();
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
void __stdcall FUN_001db110(unsigned int unused) {
 Manager_1db110* manager = FUN_001d4c90();
 if (manager) {
  char name[256];
  strncpy(name,"CollapseRoof",256);
  name[255]=0;
  Options options;
  options.FUN_001d1630();
  options.first=0;
  strncpy(name,"HandleLuaCalls",256);
  name[255]=0;
  manager->FUN_001d3b00(name,options);
 }
}
