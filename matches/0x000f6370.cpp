struct API {
    void A(int);
    int B(int, int, int, int*);
    void C(int);
};
struct V {
    int a;
    int b;
    int c;
};
struct S_f6370 {
    API* api;
    int b;
    int c;
    int d;
    V Target();
};
V S_f6370::Target() {
    V local;
    api->A(0);
    int r = api->B(c, d, 0, (int*)&local);
    api->C(r);
    return local;
}
