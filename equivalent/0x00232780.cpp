// STATUS: equivalent (tools/equiv.py level 3: 2986 inputs, branch coverage 2/2)
// FUN_00232780 @ 0x00232780
extern int __cdecl FUN_00238190(int);
extern int __cdecl FUN_00266da0(int);
extern void* __cdecl FUN_0008d690(int);
extern int* DAT_004e5af8;

int* __cdecl FUN_00232780() {
    int value = FUN_00266da0(FUN_00238190(0));
    int* result = static_cast<int*>(FUN_0008d690(4));
    if (result) *result = 0;
    DAT_004e5af8 = result;
    FUN_00266da0(value);
    return result;
}