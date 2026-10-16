class X {
    char pad[12];
    int value;

  public:
    bool Set(int v);
};
bool X::Set(int v) {
    value = v;
    return true;
}