class Obj {
  public:
    char pad[16];
    int m10;
    char Fn(int value);
};

char Obj::Fn(int value) {
    m10 = value;
    return 1;
}
