class Obj {
    char pad[0x10];

  public:
    bool Set(int value);
};
bool Obj::Set(int value) {
    *(int*)((char*)this + 0x10) = value;
    return true;
}