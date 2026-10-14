class Obj_5d8c0 {
    char pad[0x28];

  public:
    bool Set(int value);
};

bool Obj_5d8c0::Set(int value) {
    *(int*)((char*)this + 0x28) = value;
    return true;
}
