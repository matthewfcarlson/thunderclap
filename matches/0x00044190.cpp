class C {
  public:
    char pad[0x1cb0];
    int m;
    void Set(int v);
};

void C::Set(int v) {
    m = v;
}
