struct ExecuteTrack {
    char pad0[0x14];
    int field14;
    char pad18[8];
    int field20;
    char field24;
    int vfunc_10(int a, int b, int c);
};
struct ExecuteAction_239bd0 {
    int FUN_002397c0(int, ExecuteTrack*, int, int, void*, int, int);
};
extern "C" ExecuteAction_239bd0* __cdecl FUN_0008d690(int);
int ExecuteTrack::vfunc_10(int a, int b, int c) {
    ExecuteAction_239bd0* p = FUN_0008d690(0x68);
    int result;
    if (p) {
        int x = field20;
        int y = field14;
        result = p->FUN_002397c0(a, this, y, x, &field24, b, c);
    } else
        result = 0;
    return result;
}