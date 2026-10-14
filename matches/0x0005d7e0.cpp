class Obj_5d7e0 {
  public:
    char pad[0x1c];
    int m1c;
    bool Set(int value);
};

bool Obj_5d7e0::Set(int value) {
    m1c = value;
    return true;
}