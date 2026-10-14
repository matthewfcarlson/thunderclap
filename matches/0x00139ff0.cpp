class Obj_139ff0 {
  public:
    char Pad[0x50];
    int mField;
    char Fn(int value);
};

char Obj_139ff0::Fn(int value) {
    mField = value;
    return 1;
}