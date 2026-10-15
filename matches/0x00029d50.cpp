struct Result {
    char Check();
};
struct Owner {
    Result* Get(unsigned a, unsigned b);
    char Fn(unsigned x);
};
extern "C" unsigned __int64 __cdecl External(unsigned x, unsigned a, unsigned b);
char Owner::Fn(unsigned x) {
    unsigned __int64 v = External(x, 0, 0);
    Result* r = Get((unsigned)v, (unsigned)(v >> 32));
    if (!r)
        return 0;
    return r->Check();
}