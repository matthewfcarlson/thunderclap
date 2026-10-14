class Obj {
  public:
    char Set(int value);
    char pad[0xb8];
};
char Obj::Set(int value) {
    *(int*)((char*)this + 0xb8) = value;
    return 1;
}
