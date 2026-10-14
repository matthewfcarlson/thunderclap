extern void* g_00554c30;
extern "C" void thunk_FUN_00267090(void*);
void FUN_002f2cf0() {
    void* p = g_00554c30;
    if (p)
        thunk_FUN_00267090(p);
    g_00554c30 = 0;
}
