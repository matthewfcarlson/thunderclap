class Obj_48170 {
  public:
    char pad[12];
    int mField;
    bool Set(int value);
};

bool Obj_48170::Set(int value) {
    mField = value;
    return true;
}