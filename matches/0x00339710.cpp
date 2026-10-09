extern int FUN_00212d70(void*);
extern void FUN_00213640(void*, int, int);
extern void FUN_00213870(void*, int, int);
extern void FUN_00213360(void*, int);
void __cdecl FUN_00339710(void* param_1, int param_2, int param_3)
{
    if (param_3 >= 0) {
        if (param_2 <= 0 && param_2 > -10000)
            param_2 = param_2 + 1 + FUN_00212d70(param_1);
        FUN_00213640(param_1, param_2, 1);
        FUN_00213870(param_1, param_2, param_3);
        FUN_00213360(param_1, param_3);
        FUN_00213870(param_1, param_2, 1);
    }
}