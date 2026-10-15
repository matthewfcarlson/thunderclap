extern void* g_obj;
extern void* __cdecl thunk_FUN_00267090(void*);
extern void __cdecl FUN_0027b1d0();

void FUN_00292530() {
    FUN_0027b1d0();
    if (g_obj) {
        thunk_FUN_00267090(g_obj);
    }
    g_obj = 0;
}
