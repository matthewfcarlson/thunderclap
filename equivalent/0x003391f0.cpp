// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_003391f0 @ 0x003391f0
void __cdecl FUN_00213640(void *L, int index, int n);
int __cdecl FUN_00212f00(void *L, int index);
void __cdecl FUN_00212d80(void *L, int index);
void __cdecl FUN_00213680(void *L, int narr, int nrec);
void __cdecl FUN_00212ed0(void *L, int index);
void __cdecl FUN_002138e0(void *L, int index);
void __cdecl FUN_00213380(void *L, const char *s, int len);
void __cdecl FUN_00213790(void *L, int index, const char *key);
void __cdecl FUN_00213870(void *L, int index, int n);

// equiv-conv: FUN_003391f0 esi
void FUN_003391f0(void *L)
{
    FUN_00213640(L, -10000, 2);
    if (FUN_00212f00(L, -1) == 0) {
        FUN_00212d80(L, -2);
        FUN_00213680(L, 0, 0);
        FUN_00212ed0(L, -1);
        FUN_002138e0(L, -2);
        FUN_00213380(L, "kv", 2);
        FUN_00213790(L, -2, "__mode");
        FUN_00212ed0(L, -1);
        FUN_00213870(L, -10000, 2);
    }
}
