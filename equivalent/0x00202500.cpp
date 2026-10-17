// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00202500 @ 0x00202500
struct Triple { int x,y,z; };
void __stdcall FUN_00201f20(void* input, int count, Triple* result, void* scratch, int a, int b);
void __stdcall FUN_00202500(Triple* output, int a, int b, int c)
{
    Triple result = {0,0,0};
    char scratch[12];
    FUN_00201f20(&a, 1, &result, scratch, 0, 0);
    *output = result;
}