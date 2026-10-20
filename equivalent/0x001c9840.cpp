// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001c9840 @ 0x001c9840
// cl-flags: /GS
struct Vec3_1c9840 { float x,y,z; };
struct Writer_1c9840 {
 bool FUN_001d2e80();
 void FUN_001d1d50(const char*, const char*);
 void FUN_001d1e50(const char*, Vec3_1c9840);
 void FUN_001d1d10();
};
void __cdecl FUN_00096d50(char*, int, unsigned int, unsigned int);
struct Actor_1c9840 {
 char pad0[0x14];
 char actor[0x40];
 char templ[0x20];
 char variation[0x24];
 unsigned int teamLow;
 unsigned int teamHigh;
 Vec3_1c9840 position;
 Writer_1c9840* FUN_001d4c90();
 bool target();
};
bool Actor_1c9840::target() {
 Writer_1c9840* writer = FUN_001d4c90();
 if (!writer || !writer->FUN_001d2e80()) {
 return false;
 }
 writer->FUN_001d1d50("actor", actor);
 writer->FUN_001d1d50("template", templ);
 writer->FUN_001d1d50("template_variation", variation);
 writer->FUN_001d1e50("position", position);
 char team[32];
 FUN_00096d50(team,32,teamLow,teamHigh);
 writer->FUN_001d1d50("team",team);
 writer->FUN_001d1d10();
 return true;
}