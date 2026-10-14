// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_0007e680 @ 0x0007e680
extern "C" int __cdecl FUN_000964a0(char*, unsigned, const char*, ...);
extern "C" int __cdecl FUN_000113e0(int, int);
extern unsigned DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned);
struct VehicleManager {
 char pad[0x36f0];
 int limits[10];
 int counts[10];
 int count;
 char pad2[0x5c];
 int vehicle;
 void FUN_0007db80(int*, int*);
 void FUN_0007d700(const char*, int, int, int);
 void FUN_0007e680();
};
void VehicleManager::FUN_0007e680() {
 unsigned cookie = DAT_004d9968;
 int first, second;
 FUN_0007db80(&first, &second);
 if (first != -1 && second != -1) {
  char name[32];
  FUN_000964a0(name, 32, "vehicle%d", vehicle);
  unsigned index = FUN_000113e0(0, count - 1);
  int n = count;
  for (int i = 0; i < n; ++i) {
   if (counts[index] < limits[index]) {
    FUN_0007d700(name, index, first, second);
    break;
   }
   index = (index + 1) % (unsigned)n;
  }
 }
 __security_check_cookie(cookie);
}
