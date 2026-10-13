// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_002710d0 @ 0x002710d0
struct Source {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual int status();
};
struct Slot { Source *source; char rest[0x118]; };
struct Result { Result *FUN_002764d0(Source *, int, int, int, int, int, int, int, int); };
struct Work { volatile int first, second; int key; char gap[16]; char buffer[0x100]; char pad[0x20]; };
extern char DAT_004cdc04;
extern char DAT_0052a0f0;
extern int DAT_0052a120;
extern Slot DAT_0052842c[];
void __cdecl FUN_002697c0(int, void *, void *, volatile int *, volatile int *);
int __cdecl FUN_0026d850(void *);
int __cdecl FUN_0026d840(void *);
int __cdecl FUN_00270c10(void *);
void __cdecl FUN_00270f10(void *, int);
Result * __cdecl FUN_00275d50(int);
int __cdecl FUN_002710d0(Result **out, int input, int a, int b, int c, int d, int e, int f) {
 Work work;
 work.first = 0;
 work.second = 0;
 FUN_002697c0(input, work.buffer, &work.key, &work.second, &work.first);
 FUN_0026d850(&DAT_0052a0f0);
 int index = FUN_00270c10(&work.key);
 Slot *slot = index == -1 ? 0 : &DAT_0052842c[index];
 if (!slot || !slot->source) {
  if (DAT_004cdc04) {
   FUN_0026d840(&DAT_0052a0f0);
   FUN_00270f10(&work.key, DAT_0052a120);
   FUN_0026d850(&DAT_0052a0f0);
   index = FUN_00270c10(&work.key);
   slot = index >= 0 ? &DAT_0052842c[index] : 0;
  }
 }
 if (!slot || !slot->source) {
  *out = 0;
  return FUN_0026d840(&DAT_0052a0f0);
 }
 int selected = work.second;
 int status = slot->source->status();
 if ((signed char)status < 0) selected = work.first;
 Result *result = FUN_00275d50(0x168);
 if (result) result = result->FUN_002764d0(slot->source, selected, a, b, c, d, e, f, 1);
 *out = result;
 return FUN_0026d840(&DAT_0052a0f0);
}