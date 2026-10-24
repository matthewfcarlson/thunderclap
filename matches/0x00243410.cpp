extern bool __cdecl ReadValue(int, int*);
class C_243410 {
  public:
    int value;
    int out;
};
bool __fastcall Target(C_243410* self) {
    int a, b, c;
    int x = self->value;
    if (!ReadValue(x, &a))
        return false;
    if (!ReadValue(x, &b))
        return false;
    if (!ReadValue(x, &c))
        return false;
    if (a != 0xff443350)
        return false;
    if (b != 12)
        return false;
    self->out = c - 12;
    return true;
}
