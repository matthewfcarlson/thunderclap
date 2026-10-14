class Obj_139f80 {
  public:
    char pad[0x3c];
    char SetX(int value);
};

char Obj_139f80::SetX(int value) {
    *(int*)((char*)this + 0x3c) = value;
    return 1;
}
