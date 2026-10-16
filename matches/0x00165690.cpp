class Obj {
    char pad[12];
    char value;

  public:
    bool Set(char v);
};
bool Obj::Set(char v) {
    value = v;
    return true;
}