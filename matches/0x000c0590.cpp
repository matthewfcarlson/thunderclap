// Same code shape as 0x000c0500 (propagated; names are from that function)
extern long __cdecl atol(const char*);
struct Inner_c0590 {
    void call(long);
};
struct Obj_c0590 {
    int pad;
    Inner_c0590* value;
    long run(int count, char** strings);
};
long Obj_c0590::run(int count, char** strings) {
    if (!value)
        return -1;
    long n = 0;
    if (count > 0)
        n = atol(*strings);
    value->call(n);
    return 0;
}