// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001c9970 @ 0x001c9970
extern unsigned int DAT_004d9968;
void __fastcall __security_check_cookie(unsigned int);
struct Service {
 bool FUN_001d2e80();
 void FUN_001d1d50(const char*, const char*);
 void FUN_001d1e10(const char*, int);
 void FUN_001d1d10();
};
Service* __cdecl FUN_001d4c90();
void __cdecl FUN_00096d50(char*, unsigned int, unsigned int, unsigned int);
struct Object {
 char padding[0xb0];
 unsigned int originLow;
 unsigned int originHigh;
 unsigned char devastator;
 bool FUN_001c9840();
 bool target();
};
bool Object::target() {
 unsigned int cookie = DAT_004d9968;
 bool result = false;
 if (FUN_001c9840()) {
  Service* service = FUN_001d4c90();
  if (service && service->FUN_001d2e80()) {
   char origin[32];
   FUN_00096d50(origin, 32, originLow, originHigh);
   service->FUN_001d1d50("origin", origin);
   service->FUN_001d1e10("devastator", devastator);
   service->FUN_001d1d10();
   result = true;
  }
 }
 __security_check_cookie(cookie);
 return result;
}