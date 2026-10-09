class C {
    char pad[0x34];
    int a, b, c;

  public:
    void set(int x, int y, int z);
};
void C::set(int x, int y, int z) {
    a = x;
    b = y;
    c = z;
}