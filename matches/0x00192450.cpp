class Obj {
  public:
    char pad[0x7c];
    int value;
    char Fn(int arg);
};

char Obj::Fn(int arg) {
    value = arg;
    return 1;
}
