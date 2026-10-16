class Obj {
    char pad[0x80];
    int a, b, c, d;

  public:
    void Set(int x, int y, int z, int w);
};
void Obj::Set(int x, int y, int z, int w) {
    a = x;
    b = y;
    c = z;
    d = w;
}