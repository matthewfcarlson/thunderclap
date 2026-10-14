class Obj_68300 {
  public:
    char pad[0x14];
    int mX;
    bool SetX(int v);
};
bool Obj_68300::SetX(int v) {
    mX = v;
    return true;
}
