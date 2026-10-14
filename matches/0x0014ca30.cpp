class Obj_14ca30 {
  public:
    char pad[0x44];
    int mVal;
    bool Init(int x);
};

bool Obj_14ca30::Init(int x) {
    mVal = x;
    return true;
}
