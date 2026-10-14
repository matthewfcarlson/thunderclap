class Obj_1436b0 {
  public:
    char m[0x20];
    char Set(int value);
};

char Obj_1436b0::Set(int value) {
    *(int*)(m + 0x20) = value;
    return 1;
}
