class Obj {
  public:
    char Pad[0x50];
    int mField;
    char Fn(int value);
};

char Obj::Fn(int value) {
    mField = value;
    return 1;
}