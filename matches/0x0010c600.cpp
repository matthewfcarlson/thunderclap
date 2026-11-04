class Obj_10c600 {
  public:
    char pad[0xc];
    int mValue;
    bool SetTimeBegin_0010c600(int v);
};

bool Obj_10c600::SetTimeBegin_0010c600(int v) {
    mValue = v;
    return true;
}