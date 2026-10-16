struct V {
    int x, y, z;
};
class C {
    char pad[0xe0];
    V v;

  public:
    V Get();
};
V C::Get() {
    return v;
}