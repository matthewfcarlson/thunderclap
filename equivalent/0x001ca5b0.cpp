// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001ca5b0 @ 0x001ca5b0
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
struct Actor { const char* FUN_00036d00(); };
struct Lookup { Actor* FUN_00059c10(unsigned int); };
struct Manager { char pad[0x44]; Lookup* lookup; };
extern Manager* DAT_004dd700;
struct Reporter { bool FUN_001d2e80(); void FUN_001d1d50(const char*, const char*); void FUN_001d1d10(); };
extern void __cdecl FUN_00096d50(char*, unsigned int, unsigned int, unsigned int);
struct Target { char pad[0x10]; unsigned int actor; char pad14[4]; unsigned int propLow,propHigh,typeLow,typeHigh; Reporter* FUN_001d4c90(); bool FUN_001ca5b0(); };
bool Target::FUN_001ca5b0() {
 unsigned int cookie=DAT_004d9968;
 Reporter* reporter = FUN_001d4c90();
 if (!reporter || !reporter->FUN_001d2e80()) { __security_check_cookie(cookie); return false; }
 char buffer[32];
 FUN_00096d50(buffer,32,propLow,propHigh);
 reporter->FUN_001d1d50("prop",buffer);
 FUN_00096d50(buffer,32,typeLow,typeHigh);
 reporter->FUN_001d1d50("prop_type",buffer);
 Manager* manager=DAT_004dd700;
 unsigned int id=actor;
 if (!manager) { reporter->FUN_001d1d10(); __security_check_cookie(cookie); return false; }
 Actor* found=manager->lookup->FUN_00059c10(id);
 const char* name=found ? found->FUN_00036d00() : "UNKNOWN";
 reporter->FUN_001d1d50("actor",name);
 reporter->FUN_001d1d50("prop_DANGEROUS","prop_DANGEROUS is not defined in RELEASE!");
 reporter->FUN_001d1d50("prop_type_DANGEROUS","prop_type_DANGEROUS is not defined in RELEASE!");
 reporter->FUN_001d1d10();
 __security_check_cookie(cookie);
 return true;
}