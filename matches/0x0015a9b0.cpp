class Obj {
  public:
    char pad[0x2c];
    int m2c;
    bool Init(int a);
};

bool Obj::Init(int a) {
    m2c = a;
    return true;
}
