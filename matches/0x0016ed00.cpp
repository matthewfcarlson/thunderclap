class Obj_16ed00 {
  public:
    char pad[0x30];
    int m30;
    bool SetX(int v);
};

bool Obj_16ed00::SetX(int v) {
    m30 = v;
    return true;
}
