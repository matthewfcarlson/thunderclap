class Obj {
  public:
    char pad[0x1c];
    int m1c;
    bool Set(int value);
};

bool Obj::Set(int value) {
    m1c = value;
    return true;
}