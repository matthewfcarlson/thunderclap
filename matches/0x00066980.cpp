struct Obj {
    char pad[16];
    unsigned __int64 val;
};
int __cdecl FUN_00066980(const unsigned __int64* a, const Obj* b) {
    const unsigned __int64* p = &b->val;
    if (*a < *p)
        return -1;
    if (*p < *a)
        return 1;
    return 0;
}