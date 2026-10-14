class Obj {
  public:
    char Set(int value);
};
char Obj::Set(int value) {
    *((int*)((char*)this + 0x3c)) = value;
    return 1;
}