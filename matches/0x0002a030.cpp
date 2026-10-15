struct Result {
    char pad[0x1f50];
    char flag;
};
struct X {
    Result* Make(unsigned int, unsigned int);
    void Func(int v, char flag);
};
extern "C" unsigned __int64 __cdecl Other(int, int, int);
void X::Func(int v, char flag) {
    unsigned __int64 n = Other(v, 0, 0);
    Result* p = Make((unsigned int)n, (unsigned int)(n >> 32));
    if (p)
        p->flag = flag;
}