class Obj {
    char pad[16];
    int value;

  public:
    bool SetTimeEnd_00068320(int v);
};
bool Obj::SetTimeEnd_00068320(int v) {
    value = v;
    return true;
}