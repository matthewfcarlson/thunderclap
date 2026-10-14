class Obj_17fe60 {
  public:
    char pad[0x10];
    int mField;
    char Set(int value);
};

char Obj_17fe60::Set(int value) {
    mField = value;
    return 1;
}
