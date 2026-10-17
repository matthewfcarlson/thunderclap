// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0021e2b0 @ 0x0021e2b0
struct Context { char pad[0x1c]; int handle; };
struct Result { int value; int unknown1; int unknown2; int status; int result; };
extern void __cdecl FUN_0021ded0(Context*, Result*, int);
extern void __cdecl FUN_002214b0(int, Result*);
extern void __cdecl FUN_00220d70(int, int);
// equiv-conv: FUN_0021e2b0 esi
int FUN_0021e2b0(Context* context) {
    Result result;
    FUN_0021ded0(context, &result, 0);
    if (result.value == 1) result.value = 3;
    FUN_002214b0(context->handle, &result);
    FUN_00220d70(context->handle, result.status);
    return result.result;
}