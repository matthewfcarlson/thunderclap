class Obj {
  public:
    char pad[0x30];
    int m30;
    bool SetX(int v);
};

bool Obj::SetX(int v) {
    m30 = v;
    return true;
}
