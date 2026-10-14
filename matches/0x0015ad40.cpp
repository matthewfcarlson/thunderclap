class Obj {
  public:
    char pad[0x9c];
    int m9c;
    bool SetX(int x);
};

bool Obj::SetX(int x) {
    m9c = x;
    return true;
}
