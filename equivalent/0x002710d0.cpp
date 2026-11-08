// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 14/14)
// FUN_002710d0 @ 0x002710d0
#include "decls/data/engine/unknown.h"
#include "compat/ptr.h"

struct Source_2710d0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual int status();
};
// the drive registry (records.h CoreDriveRegistryEntry): the entry's drive
struct File_2710d0;
// core::File (0x002764d0 constructs it): a stand-in named by its constructor's address, with its layout (records.h
// CoreFile, 0x168 bytes on the 32-bit build), so that the allocation is the class's size on every target
inline void* operator new(unsigned int, void* p) { return p; }
struct FUN_002764d0 : CoreFile {
 FUN_002764d0(Source_2710d0 *, const char *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned char);
};
struct Work_2710d0 { const char* volatile first; char* volatile second; int key; char gap[16]; char buffer[0x100]; char pad[0x20]; };
extern "C" void __cdecl FUN_002697c0(const char *source, char *output, char *workspace, char **suffix, const char **remainder);
extern "C" void FUN_0026d850(void *arg);
extern "C" int FUN_0026d840(void *arg);
extern "C" int __cdecl FUN_00270c10(const char *);
extern "C" int __cdecl FUN_00270f10(const char *, void *);
extern "C" void * __cdecl FUN_00275d50(unsigned int);
int __cdecl FUN_002710d0(File_2710d0 **out, const char *input, int a, int b, int c, int d, int e, int f) {
 Work_2710d0 work;
 work.first = 0;
 work.second = 0;
 FUN_002697c0(input, work.buffer, (char *)&work.key, (char **)&work.second, (const char **)&work.first);
 FUN_0026d850(((char*)DAT_0052a0f0));
 int index = FUN_00270c10((const char *)(void *)(&work.key));
 void **slot = index == -1 ? 0 : &DAT_00528418[index].drive;
 if (!slot || !*slot) {
  if ((*(char*)&DAT_004cdc04)) {
   FUN_0026d840(((char*)DAT_0052a0f0));
   FUN_00270f10((const char *)(void *)(&work.key), (void *)(hulk_uintptr)(int)DAT_0052a120);
   FUN_0026d850(((char*)DAT_0052a0f0));
   index = FUN_00270c10((const char *)(void *)(&work.key));
   slot = index >= 0 ? &DAT_00528418[index].drive : 0;
  }
 }
 if (!slot || !*slot) {
  *out = 0;
  return FUN_0026d840(((char*)DAT_0052a0f0));
 }
 const char *selected = work.second;
 int status = ((Source_2710d0 *)*slot)->status();
 if ((signed char)status < 0) selected = work.first;
 HULK_SIZE32(FUN_002764d0, 0x168);
 FUN_002764d0 *result = (FUN_002764d0 *)FUN_00275d50((unsigned int)sizeof(FUN_002764d0));
 if (result) result = new (result) FUN_002764d0((Source_2710d0 *)*slot, selected, a, b, c, d, e, f, 1);
 *out = (File_2710d0 *)result;
 return FUN_0026d840(((char*)DAT_0052a0f0));
}