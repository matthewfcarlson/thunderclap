class C {
    char pad[0x1e4];
    int a;
    int d;
    int c;
    int b;
    int e;
    int f;
    int count;

  public:
    void Set(bool x);
};
void C::Set(bool x) {
    if (x) {
        ++count;
        if (count > 0) {
            a = 0;
            b = 0;
            c = 0;
            d = 0;
            e = 0;
            f = 0;
        }
    } else
        --count;
}