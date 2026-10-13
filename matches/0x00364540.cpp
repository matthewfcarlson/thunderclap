class Obj {
  public:
    void Run();
};
extern Obj gObj;
void __cdecl FUN_00364540() {
    gObj.Run();
}