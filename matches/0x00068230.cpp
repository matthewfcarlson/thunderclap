class Obj {
  public:
    char pad[0x6c];
    int value;
    bool FUN_00068230(int x);
};

bool Obj::FUN_00068230(int x) {
    value = x;
    return true;
}
