class Obj_15b5b0 {
  public:
    char Set(int value);
    char pad[0x24];
};
char Obj_15b5b0::Set(int value) {
    *(int*)((char*)this + 0x24) = value;
    return 1;
}