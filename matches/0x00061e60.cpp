class Obj_61e60 {
  public:
    char Set(int value);
    char pad[12];
    int mField;
};

char Obj_61e60::Set(int value) {
    mField = value;
    return 1;
}
