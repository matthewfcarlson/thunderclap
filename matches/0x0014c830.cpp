class Obj {
  public:
    char Pad[0x20];
    int Value;
    char Fn(int arg);
};

char Obj::Fn(int arg) {
    Value = arg;
    return 1;
}
