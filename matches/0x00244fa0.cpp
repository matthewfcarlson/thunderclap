extern "C" int helper(void*, void*);
extern void* g_context;
extern int g_enabled;
extern "C" int FUN_00244fa0(unsigned int* a, unsigned int* b) {
    if (!g_enabled)
        return 0;
    unsigned int local[4];
    local[0] = a[0];
    local[1] = a[1];
    local[2] = b[0];
    local[3] = b[1];
    return helper(g_context, local);
}