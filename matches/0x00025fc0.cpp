extern "C" __int64 __cdecl FUN_002672f0(int, int, int);
class Obj {
  public:
    int FUN_00024280(__int64);
    void FUN_00025e50(int);
    void Target(int);
};
void Obj::Target(int x) {
    FUN_00025e50(FUN_00024280(FUN_002672f0(x, 0, 0)));
}
