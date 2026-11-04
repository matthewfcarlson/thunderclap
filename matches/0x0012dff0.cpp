class Obj {
  public:
    char pad[12];
    int value;
    bool SetUnlockable_0012dff0(int x);
};
bool Obj::SetUnlockable_0012dff0(int x) {
    value = x;
    return true;
}