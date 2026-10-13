class Obj {
  public:
    char pad[0x2c];
    bool Set(int value);
};

bool Obj::Set(int value) {
    *(int*)((char*)this + 0x2c) = value;
    return true;
}