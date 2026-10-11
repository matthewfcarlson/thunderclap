extern "C" char DAT_004325f4[];
class Obj {
  public:
    int vptr;
    void Init();
    Obj();
};
Obj::Obj() {
    Init();
    vptr = ((int)DAT_004325f4);
}