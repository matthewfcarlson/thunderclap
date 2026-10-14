struct B_23ada0 {
    void Take(void* p);
};
extern "C" void* F238190(int a);
extern "C" void* F266e00(void* a, int n);
extern "C" void F267090(void* p);
struct A_23ada0 {
    bool Size(int a, int* n);
    bool Fill(int a, void* p, int n);
    bool Fn(int a, B_23ada0* b);
};
bool A_23ada0::Fn(int a, B_23ada0* b) {
    int n = 0;
    if (!Size(a, &n))
        return false;
    int len = n + 1;
    void* p = F266e00(F238190(1), len);
    bool r = Fill(a, p, len);
    if (!r)
        return false;
    b->Take(p);
    F267090(p);
    return r;
}
