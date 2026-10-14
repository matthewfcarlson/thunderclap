class Obj_15b250 {
  public:
    char Set(int value);
    char pad[0xb8];
};
char Obj_15b250::Set(int value) {
    *(int*)((char*)this + 0xb8) = value;
    return 1;
}
