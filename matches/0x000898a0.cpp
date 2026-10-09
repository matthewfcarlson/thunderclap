class Obj {
    char pad[0xf8];
    unsigned int a, b, c;

  public:
    void Set(unsigned int x, unsigned int y, unsigned int z);
};
void Obj::Set(unsigned int x, unsigned int y, unsigned int z) {
    a = x;
    b = y;
    c = z;
}