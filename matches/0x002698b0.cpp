typedef int(__cdecl* Dummy_2698b0)(void);
extern int __cdecl FUN_002673d0(char*, int);
int __cdecl FUN_002698b0(char* param_1) {
    if (*param_1 == '\\')
        ++param_1;
    return FUN_002673d0(param_1, 0);
}
