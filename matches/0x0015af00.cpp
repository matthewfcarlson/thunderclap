class Obj_15af00 {
  public:
    char pad[0x34];
    int m34;
    bool Set(int value);
};

bool Obj_15af00::Set(int value) {
    m34 = value;
    return true;
}