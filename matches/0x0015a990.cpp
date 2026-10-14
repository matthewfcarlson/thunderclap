class Obj_15a990 {
  public:
    bool SetX(int value);
    char pad[0x28];
    int mValue;
};

bool Obj_15a990::SetX(int value) {
    mValue = value;
    return true;
}
