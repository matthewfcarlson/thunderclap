// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 10/10)
// FUN_0007e680 @ 0x0007e680
// cl-flags: /GS
extern "C" int __cdecl FUN_000964a0(char*, unsigned, const char*, ...);
extern "C" int __cdecl FUN_000113e0(int, int);
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
 struct { int second, first; } o;  // original frame: second at S+0, first at S+4 (the call passes &first, &second)
 FUN_0007db80(&o.first, &o.second);
 if (o.first != -1 && o.second != -1) {
  char name[32];
  FUN_000964a0(name, 32, "vehicle%d", vehicle);
  unsigned index = FUN_000113e0(0, count - 1);
  int n = count;
  for (int i = 0; i < n; ++i) {
   if (counts[index] < limits[index]) {
    FUN_0007d700(name, index, o.first, o.second);
    break;
   }
   index = (index + 1) % (unsigned)n;
  }
 }
}
