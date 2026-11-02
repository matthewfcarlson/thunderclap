// b..d: a vector passed by value (FUN_001dc420 copies its three words). A by-value struct parameter can't be
// declared in include/gen (tools/gen_headers.py nv_sig_type), so the member is defined on a local stand-in.
struct Vec3_1df1e0 {
    float x, y, z;
};

struct CSPManager_1df1e0 {
    int Find(int);
    char Do(int, Vec3_1df1e0*);
    char FUN_001df1e0(int a, Vec3_1df1e0 b);
};

char CSPManager_1df1e0::FUN_001df1e0(int a, Vec3_1df1e0 b) {
    int n = Find(a);
    if (n < 0)
        return 0;
    return Do(n, &b);
}
