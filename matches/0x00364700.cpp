class Obj {
  public:
    void Run();
};
extern Obj gObj;
void __cdecl FUN_00364700() {
    gObj.Run();
}
