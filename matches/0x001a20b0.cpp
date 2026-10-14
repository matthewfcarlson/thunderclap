class Obj_1a20b0 {
  public:
    char Set(int value);
    char pad[0x50];
};

char Obj_1a20b0::Set(int value) {
    *(int*)(pad + 0x50) = value;
    return 1;
}