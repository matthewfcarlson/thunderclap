extern long __cdecl atol(const char*);
struct Inner_c0500 {
    void call(long);
};
struct Obj_c0500 {
    int pad;
    Inner_c0500* value;
    long run(int count, char** strings);
};
long Obj_c0500::run(int count, char** strings) {
    if (!value)
        return -1;
    long n = 0;
    if (count > 0)
        n = atol(*strings);
    value->call(n);
    return 0;
}