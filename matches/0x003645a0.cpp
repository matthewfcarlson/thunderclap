class Obj {
  public:
    void Fn();
};
extern Obj gObj;
void __cdecl Target() {
    gObj.Fn();
}
