class Obj_61ee0 {
  public:
    char pad[0x2c];
    bool Set(int value);
};

bool Obj_61ee0::Set(int value) {
    *(int*)((char*)this + 0x2c) = value;
    return true;
}