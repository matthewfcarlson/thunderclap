class Obj {
    char pad[0x10];

  public:
    int value;
    bool SetFlag(int x);
};
bool Obj::SetFlag(int x) {
    value = x;
    return true;
}