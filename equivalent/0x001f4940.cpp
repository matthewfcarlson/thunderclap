// STATUS: equivalent (tools/equiv.py level 3: 2969 inputs, branch coverage 4/4)
// FUN_001f4940 @ 0x001f4940
struct Thing { void *unused; void *handle; void FUN_001f4940(); };
extern char __cdecl FUN_00249b40(void *);
extern void __cdecl FUN_0024a800(void *, int);
extern void __cdecl FUN_00240bb0();
extern void __cdecl FUN_002656a0();
void Thing::FUN_001f4940() {
    while (handle && !FUN_00249b40(handle)) {
        FUN_0024a800(handle, 10);
        FUN_00240bb0();
        FUN_002656a0();
    }
}