class Obj_11ba10 {
  public:
    char pad[0x20];
    int m20;
    bool Set(int value);
};

bool Obj_11ba10::Set(int value) {
    m20 = value;
    return true;
}
