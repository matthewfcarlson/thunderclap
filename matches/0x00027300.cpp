struct Result {
    char pad[0x1d48];
    int value;
};
struct Obj {
    Result* setPair(int a, int b);
    void assign(int a, int b);
};
extern "C" unsigned __int64 __cdecl makePair(int a, int b, int c);
void Obj::assign(int a, int b) {
    unsigned __int64 v = makePair(a, 0, 0);
    Result* p = setPair((int)v, (int)(v >> 32));
    if (p)
        p->value = b;
}