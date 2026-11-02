extern "C" bool __cdecl FUN_0025abd0(int, int*);
class C_243410 {
  public:
    int value;
    int out;
};
bool __fastcall Target(C_243410* self) {
    int a, b, c;
    int x = self->value;
    if (!FUN_0025abd0(x, &a))
        return false;
    if (!FUN_0025abd0(x, &b))
        return false;
    if (!FUN_0025abd0(x, &c))
        return false;
    if (a != 0xff443350)
        return false;
    if (b != 12)
        return false;
    self->out = c - 12;
    return true;
}
