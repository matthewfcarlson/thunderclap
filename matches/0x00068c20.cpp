class Obj_68c20 {
  public:
    char pad[0x24];
    char Set(int value);
};
char Obj_68c20::Set(int value) {
    *((int*)((char*)this + 0x24)) = value;
    return 1;
}
