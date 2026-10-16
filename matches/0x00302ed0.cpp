class Obj {
  public:
    char pad[8];
    int a;
    int b;
    int c;
    void Fn(int x, int y, int z);
    void Other(int x, int y);
};
void Obj::Fn(int x, int y, int z) {
    b = c;
    a = z;
    Other(x, y);
}