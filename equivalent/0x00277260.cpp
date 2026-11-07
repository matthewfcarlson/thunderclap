// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00277260 @ 0x00277260
// FUN_00277260 @ 0x00277260
// equiv-conv: FUN_0026fcf0 stack stack stack stack
int __cdecl FUN_0026fcf0(void **result, const char *path, int heap, char *details);
extern "C" void __cdecl FUN_00278a40(void **out, const char *name, int heap);
extern "C" void __cdecl FUN_00277260(void **arg1, const char *path, unsigned int arg3, char *arg4)
{
    const char *drives[4] = { "D:", "T:", "Z:", "W:" };
    for (int d = 0; d < 4; ++d) {
        int i;
        for (i = 0; i < 3 && path[i] == drives[d][i]; ++i) {}
        if (i == 3) { FUN_0026fcf0(arg1, path, (int)arg3, arg4); return; }
    }
    FUN_00278a40(arg1, path, (int)arg3);
}
