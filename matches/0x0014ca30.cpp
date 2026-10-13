class Obj {
  public:
    char pad[0x44];
    int mVal;
    bool Init(int x);
};

bool Obj::Init(int x) {
    mVal = x;
    return true;
}
