class Obj {
  public:
    char Set(int value);
    char pad[0x50];
};

char Obj::Set(int value) {
    *(int*)(pad + 0x50) = value;
    return 1;
}