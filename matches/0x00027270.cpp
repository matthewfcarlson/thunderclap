class Result {
  public:
    char pad[0x2140];
    unsigned char flag;
};
extern "C" __int64 __cdecl FUN_002672f0(int, int, int);
class Obj {
  public:
    Result* FUN_00024280(__int64);
    unsigned char FUN_00027270(int);
};
unsigned char Obj::FUN_00027270(int x) {
    __int64 v = FUN_002672f0(x, 0, 0);
    Result* p = FUN_00024280(v);
    if (!p)
        return 0;
    return p->flag;
}