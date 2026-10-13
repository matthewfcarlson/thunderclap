class Obj {
  public:
    char pad[0x3c];
    char SetX(int value);
};

char Obj::SetX(int value) {
    *(int*)((char*)this + 0x3c) = value;
    return 1;
}
