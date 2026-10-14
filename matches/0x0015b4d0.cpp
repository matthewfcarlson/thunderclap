class Obj {
  public:
    char pad[0x60];
    int mValue;
    bool SetBool(int param);
};
bool Obj::SetBool(int param) {
    mValue = param;
    return true;
}
