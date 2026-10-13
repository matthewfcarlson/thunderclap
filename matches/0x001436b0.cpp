class Obj {
  public:
    char m[0x20];
    char Set(int value);
};

char Obj::Set(int value) {
    *(int*)(m + 0x20) = value;
    return 1;
}
