class X {
    char pad[0x28];
    int m;

  public:
    bool Set(int);
};

bool X::Set(int v) {
    m = v;
    return true;
}
