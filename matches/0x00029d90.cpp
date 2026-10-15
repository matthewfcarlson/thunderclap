struct Result {
    void A(int);
    void B(int);
};
struct Obj {
    Result* Find(unsigned __int64);
    void Fn(int, int);
};
extern "C" unsigned __int64 __cdecl Convert(int, int, int);
void Obj::Fn(int x, int y) {
    unsigned __int64 n = Convert(x, 0, 0);
    Result* r = Find(n);
    if (r) {
        r->A(y);
        r->B(y);
    }
}