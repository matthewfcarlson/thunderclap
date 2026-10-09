extern void* __cdecl FUN_00213d30(void*, unsigned int);
extern void __cdecl FUN_00338f30(void*, const char*);
extern void __cdecl FUN_002138e0(void*, int);

int __cdecl FUN_001d0870(void* param_1, unsigned int* param_2) {
    unsigned int* puVar1 = (unsigned int*)FUN_00213d30(param_1, 0xc);
    FUN_00338f30(param_1, "Vector");
    FUN_002138e0(param_1, -2);
    puVar1[0] = param_2[0];
    puVar1[1] = param_2[1];
    puVar1[2] = param_2[2];
    return 1;
}