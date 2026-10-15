struct Item {
    void Do(int);
};
struct Obj {
    Item* Get(__int64);
    void Target(int, int);
};
extern "C" __int64 __cdecl Hash(int, int, int);
void Obj::Target(int a, int b) {
    __int64 h = Hash(a, 0, 0);
    Item* p = Get(h);
    if (p)
        p->Do(b);
}