class Obj {
  public:
    char pad[0x38];
    int m38;
    bool operator=(int v);
};

bool Obj::operator=(int v) {
    m38 = v;
    return true;
}
