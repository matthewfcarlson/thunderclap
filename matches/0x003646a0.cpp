class Obj {
  public:
    void Run();
};
extern Obj gObj;
extern "C" void FUN_003646a0() {
    gObj.Run();
}