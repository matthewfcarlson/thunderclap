extern void* g_compare;
extern unsigned char g_zero_23fb00;
void* __fastcall FUN_0023fb00(void* p) {
    void* v = *(void**)p;
    if (v == g_compare)
        return &g_zero_23fb00;
    return v;
}