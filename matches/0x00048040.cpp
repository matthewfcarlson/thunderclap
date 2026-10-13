class Obj {
  public:
    char pad[12];
    int mX;
    char SetX(int a);
};
char Obj::SetX(int a) {
    mX = a;
    return 1;
}
