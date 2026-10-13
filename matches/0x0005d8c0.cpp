class Obj {
    char pad[0x28];

  public:
    bool Set(int value);
};

bool Obj::Set(int value) {
    *(int*)((char*)this + 0x28) = value;
    return true;
}
