// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001ca890 @ 0x001ca890
extern unsigned int DAT_004d9968;
void __fastcall __security_check_cookie(unsigned int);
struct Actor { const char* FUN_00036d00(); };
struct Registry { Actor* FUN_00059c10(unsigned int id); };
struct World { char pad[0x44]; Registry* registry; };
extern World* DAT_004dd700;
struct Writer { bool FUN_001d2e80(); void FUN_001d1d50(const char*, const char*); void FUN_001d1dd0(const char*, unsigned int); void FUN_001d1d10(); };
extern "C" void __cdecl FUN_00096d50(char*, int, unsigned int, unsigned int);
struct Target { char pad[0x10]; unsigned int actor; char pad14[4]; unsigned int propLow, propHigh, typeLow, typeHigh, attachment; Writer* FUN_001d4c90(); bool run(); };
bool Target::run() {
 unsigned int cookie = DAT_004d9968;
 Writer* writer = FUN_001d4c90();
 bool result = false;
 if (writer && writer->FUN_001d2e80()) {
 char buffer[32];
 FUN_00096d50(buffer, 32, propLow, propHigh);
 writer->FUN_001d1d50("prop", buffer);
 FUN_00096d50(buffer, 32, typeLow, typeHigh);
 writer->FUN_001d1d50("prop_type", buffer);
 writer->FUN_001d1dd0("attachment_index", attachment);
 World* world = DAT_004dd700;
 unsigned int id = actor;
 if (world) {
 Actor* a = world->registry->FUN_00059c10(id);
 const char* name = a ? a->FUN_00036d00() : "UNKNOWN";
 writer->FUN_001d1d50("actor", name);
 writer->FUN_001d1d50("prop_DANGEROUS", "prop_DANGEROUS is not defined in RELEASE!");
 writer->FUN_001d1d50("prop_type_DANGEROUS", "prop_type_DANGEROUS is not defined in RELEASE!");
 result = true;
 }
 writer->FUN_001d1d10();
 }
 __security_check_cookie(cookie);
 return result;
}