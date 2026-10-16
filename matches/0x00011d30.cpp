struct V {
    int a, b, c;
};
class X {
    char pad[0x34];
    V v;

  public:
    V Get();
};
V X::Get() {
    return v;
}