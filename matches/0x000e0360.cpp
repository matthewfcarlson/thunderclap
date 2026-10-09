class C {
    char pad[0x180c];

  public:
    int a;
    int b;
    int c;
    void Set(int x, int y, int z);
};
void C::Set(int x, int y, int z) {
    a = x;
    b = y;
    c = z;
}