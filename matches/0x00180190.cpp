class Obj_180190 {
  public:
    char pad[0x8c];
    int m8c;
    bool Set(int value);
};
bool Obj_180190::Set(int value) {
    m8c = value;
    return true;
}
