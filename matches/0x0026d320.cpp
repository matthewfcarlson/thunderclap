typedef unsigned int uint_26d320;
extern uint_26d320 __cdecl FUN_0026fd50(uint_26d320, uint_26d320);
extern uint_26d320 __cdecl FUN_0026fd80(uint_26d320, uint_26d320);
class Obj_26d320 {
  public:
    char p[24];
    uint_26d320 a, b, c, d, flag;
    uint_26d320 f(uint_26d320 x, uint_26d320 y);
};
uint_26d320 Obj_26d320::f(uint_26d320 x, uint_26d320 y) {
    uint_26d320 r;
    if (flag == 0) {
        r = FUN_0026fd50(a, y);
        if (r + x < b) {
            a = r + x;
            ++c;
            return r;
        }
    } else {
        r = FUN_0026fd80(b - x, y);
        if (r > a) {
            b = r;
            ++d;
            return r;
        }
    }
    return 0;
}