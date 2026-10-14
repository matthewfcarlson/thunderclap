// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001ca730 @ 0x001ca730
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
struct Reporter_1ca730 {
 bool FUN_001d2e80();
 void FUN_001d1d50(const char*, const char*);
 void FUN_001d1dd0(const char*, unsigned int);
 void FUN_001d1d10();
};
void __cdecl FUN_00096d50(char*, unsigned int, unsigned int, unsigned int);
struct Object {
 char pad[0x18];
 unsigned int propLo, propHi;
 unsigned int typeLo, typeHi;
 unsigned int increase;
 unsigned int unused;
 unsigned int originLo, originHi;
 Reporter_1ca730* FUN_001d4c90();
 bool target();
};
bool Object::target() {
 unsigned int cookie = DAT_004d9968;
 Reporter_1ca730* r = FUN_001d4c90();
 if (!r || !r->FUN_001d2e80()) {
 __security_check_cookie(cookie);
 return false;
 }
 char buffer[32];
 FUN_00096d50(buffer, 32, propLo, propHi);
 r->FUN_001d1d50("prop", buffer);
 FUN_00096d50(buffer, 32, typeLo, typeHi);
 r->FUN_001d1d50("prop_type", buffer);
 FUN_00096d50(buffer, 32, originLo, originHi);
 r->FUN_001d1d50("origin", buffer);
 r->FUN_001d1dd0("ers_increase", increase);
 r->FUN_001d1d50("prop_DANGEROUS", "prop_DANGEROUS is not defined in RELEASE!");
 r->FUN_001d1d50("prop_type_DANGEROUS", "prop_type_DANGEROUS is not defined in RELEASE!");
 r->FUN_001d1d10();
 __security_check_cookie(cookie);
 return true;
}
