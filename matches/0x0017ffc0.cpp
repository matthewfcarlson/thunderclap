class Obj_17ffc0 {
  public:
    char pad[0x40];
    int mValue;
    bool SetX(int value);
};
bool Obj_17ffc0::SetX(int value) {
    mValue = value;
    return true;
}