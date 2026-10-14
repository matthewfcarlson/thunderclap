class Obj_15b4d0 {
  public:
    char pad[0x60];
    int mValue;
    bool SetBool(int param);
};
bool Obj_15b4d0::SetBool(int param) {
    mValue = param;
    return true;
}
