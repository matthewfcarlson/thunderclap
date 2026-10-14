// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001caa10 @ 0x001caa10
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int cookie);
struct Properties {
 bool FUN_001d2e80();
 void FUN_001d1d50(const char* name, const char* value);
 void FUN_001d1d10();
};
extern "C" void __cdecl FUN_00096d50(char* buffer, int size, unsigned int low, unsigned int high);
struct Object {
 char padding[0x18];
 unsigned int propLow, propHigh;
 unsigned int typeLow, typeHigh;
 Properties* FUN_001d4c90();
 bool target();
};
bool Object::target() {
 unsigned int cookie = DAT_004d9968;
 Properties* properties = FUN_001d4c90();
 if (!properties || !properties->FUN_001d2e80()) {
 __security_check_cookie(cookie);
 return false;
 }
 char buffer[32];
 FUN_00096d50(buffer, 32, propLow, propHigh);
 properties->FUN_001d1d50("prop", buffer);
 FUN_00096d50(buffer, 32, typeLow, typeHigh);
 properties->FUN_001d1d50("prop_type", buffer);
 properties->FUN_001d1d50("prop_DANGEROUS", "prop_DANGEROUS is not defined in RELEASE!");
 properties->FUN_001d1d50("prop_type_DANGEROUS", "prop_type_DANGEROUS is not defined in RELEASE!");
 properties->FUN_001d1d10();
 __security_check_cookie(cookie);
 return true;
}