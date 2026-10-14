// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001d2ba0 @ 0x001d2ba0
extern "C" int __cdecl FUN_00212d70(void*);
extern "C" void __cdecl FUN_002133d0(void*, int);
extern "C" void __cdecl FUN_00213600(void*, int);
extern "C" int __cdecl FUN_00212f00(void*, int);
extern "C" void __cdecl FUN_00212d80(void*, int);
struct Object {
 char padding[8];
 void* context;
 void FUN_001d1980(int key, int mode);
 bool target(int key, int mode, bool retry);
};
bool Object::target(int key, int mode, bool retry) {
 int index = (unsigned char)mode ? -10001 : -2;
 int saved = FUN_00212d70(context);
 FUN_002133d0(context, key);
 FUN_00213600(context, index);
 if (FUN_00212f00(context, -1) == 5) return true;
 if (retry) {
  FUN_00212d80(context, -2);
  FUN_001d1980(key, mode);
  FUN_002133d0(context, key);
  FUN_00213600(context, index);
  if (FUN_00212f00(context, -1) == 5) return true;
 }
 FUN_00212d80(context, saved);
 return false;
}
