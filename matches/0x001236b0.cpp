class Obj {
  public:
    char pad[12];
    int m;
    unsigned char Fn(int x);
};
unsigned char Obj::Fn(int x) {
    m = x;
    return 1;
}
