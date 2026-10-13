class Obj {
  public:
    char pad[0x30];
    int m30;
    bool Fn(int arg);
};

bool Obj::Fn(int arg) {
    m30 = arg;
    return true;
}
