class Obj_15ad40 {
  public:
    char pad[0x9c];
    int m9c;
    bool SetX(int x);
};

bool Obj_15ad40::SetX(int x) {
    m9c = x;
    return true;
}
