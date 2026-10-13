class Obj {
  public:
    char pad[0x24];
    char Set(int value);
};
char Obj::Set(int value) {
    *((int*)((char*)this + 0x24)) = value;
    return 1;
}
