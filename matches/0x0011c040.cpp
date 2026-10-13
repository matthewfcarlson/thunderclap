class Obj {
  public:
    char pad[0x20];
    char Set(int value);
};

char Obj::Set(int value) {
    *(int*)((char*)this + 0x20) = value;
    return 1;
}
