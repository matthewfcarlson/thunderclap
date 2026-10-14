// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001cab60 @ 0x001cab60
extern unsigned int DAT_004d9968;
extern void __fastcall __security_check_cookie(unsigned int);
struct Writer_1cab60 {
 bool FUN_001d2e80();
 void FUN_001d1d50(const char*, const char*);
 void FUN_001d1dd0(const char*, int);
 void FUN_001d1d10();
};
extern const char* DAT_004c165c[];
extern void __cdecl FUN_00096d50(char*, int, unsigned int, unsigned int);
struct Object {
 char pad[0x18];
 unsigned int propLow, propHigh, typeLow, typeHigh;
 int state, increase;
 unsigned int originLow, originHigh;
 Writer_1cab60* FUN_001d4c90();
 bool FUN_001cab60();
};
bool Object::FUN_001cab60() {
 unsigned int cookie = DAT_004d9968;
 Writer_1cab60* w = FUN_001d4c90();
 if (!w || !w->FUN_001d2e80()) {
 __security_check_cookie(cookie);
 return false;
 }
 char buffer[32];
 FUN_00096d50(buffer, 32, propLow, propHigh);
 w->FUN_001d1d50("prop", buffer);
 FUN_00096d50(buffer, 32, typeLow, typeHigh);
 w->FUN_001d1d50("prop_type", buffer);
 FUN_00096d50(buffer, 32, originLow, originHigh);
 w->FUN_001d1d50("origin", buffer);
 w->FUN_001d1d50("state_desc", state == -1 ? "unDEfiNeD - tell Zaven!" : DAT_004c165c[state]);
 w->FUN_001d1dd0("ers_increase", increase);
 w->FUN_001d1d50("prop_DANGEROUS", "prop_DANGEROUS is not defined in RELEASE!");
 w->FUN_001d1d50("prop_type_DANGEROUS", "prop_type_DANGEROUS is not defined in RELEASE!");
 w->FUN_001d1d10();
 __security_check_cookie(cookie);
 return true;
}
