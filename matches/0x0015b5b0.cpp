class Obj {
  public:
    char Set(int value);
    char pad[0x24];
};
char Obj::Set(int value) {
    *(int*)((char*)this + 0x24) = value;
    return 1;
}