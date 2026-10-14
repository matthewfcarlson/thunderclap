class X_133400 {
    char pad[0x28];
    int m;

  public:
    bool Set(int);
};

bool X_133400::Set(int v) {
    m = v;
    return true;
}
