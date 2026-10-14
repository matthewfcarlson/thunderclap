class Obj_5a2e0 {
    char pad[0x10];

  public:
    int value;
    bool SetFlag(int x);
};
bool Obj_5a2e0::SetFlag(int x) {
    value = x;
    return true;
}