class Obj_207130 {
  public:
    int GetCount(int);
    void DoThing(int);
    bool Target();
};
bool Obj_207130::Target() {
    int n = GetCount(0);
    if (n > 0) {
        DoThing(n);
        return true;
    }
    return false;
}