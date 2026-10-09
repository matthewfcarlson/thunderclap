class Obj {
  public:
    int vptr;
    void Init();
    Obj();
};
Obj::Obj() {
    Init();
    vptr = 0x4325f4;
}