struct Item {
    void Set(int);
};
struct X {
    Item* Get(unsigned __int64);
    void Fn(int id, int arg);
};
extern "C" unsigned __int64 __cdecl Hash(int, int, int);
void X::Fn(int id, int arg) {
    unsigned __int64 v = Hash(id, 0, 0);
    Item* p = Get(v);
    if (p)
        p->Set(arg);
}