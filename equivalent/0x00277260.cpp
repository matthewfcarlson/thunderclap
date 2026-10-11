// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_00277260 @ 0x00277260
// equiv-conv: FUN_0026fcf0 stack stack stack
extern "C" int __cdecl FUN_0026fcf0(unsigned int, const char *, unsigned int);
extern "C" int __cdecl FUN_00278a40(unsigned int, const char *, unsigned int);
int __cdecl FUN_00277260(unsigned int arg1, const char *path, unsigned int arg3)
{
    const char *drives[4] = { "D:", "T:", "Z:", "W:" };
    for (int d = 0; d < 4; ++d) {
        int i;
        for (i = 0; i < 3 && path[i] == drives[d][i]; ++i) {}
        if (i == 3) return FUN_0026fcf0(arg1, path, arg3);
    }
    return FUN_00278a40(arg1, path, arg3);
}
