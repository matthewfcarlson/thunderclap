class Obj_11c040 {
  public:
    char pad[0x20];
    char Set(int value);
};

char Obj_11c040::Set(int value) {
    *(int*)((char*)this + 0x20) = value;
    return 1;
}
