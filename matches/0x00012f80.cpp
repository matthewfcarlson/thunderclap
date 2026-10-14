struct S_12f80 {
    int a, b, c;
};
class C_12f80 {
  public:
    char pad[0xcc];
    S_12f80 s;
    S_12f80* Get(S_12f80* p);
};
S_12f80* C_12f80::Get(S_12f80* p) {
    *p = s;
    return p;
}
