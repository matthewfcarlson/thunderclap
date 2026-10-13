class Obj {
    char pad[0x10];
    int m10;

  public:
    char Fn(int value);
};

char Obj::Fn(int value) {
    m10 = value;
    return 1;
}
