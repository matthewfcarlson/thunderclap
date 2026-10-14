class C {
  public:
    char pad[0xd4];
    int x;
    int y;
    int z;
    void Set(int a, int b, int c);
};

void C::Set(int a, int b, int c) {
    x = a;
    y = b;
    z = c;
}
