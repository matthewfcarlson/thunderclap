extern int __cdecl FUN_00212f00(int, int);
extern void __cdecl FUN_00339c30(int, int, const char *);
void __cdecl FUN_00339dc0(int param_1, int param_2)
{
    if (FUN_00212f00(param_1, param_2) == -1)
        FUN_00339c30(param_1, param_2, "value expected");
}
