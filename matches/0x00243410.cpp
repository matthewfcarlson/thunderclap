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
        goto fail;
    if (!ReadValue(x, &b))
        goto fail;
    if (!ReadValue(x, &c))
        goto fail;
    if (a != 0xff443350)
        goto fail;
    if (b != 12)
        goto fail;
    self->out = c - 12;
    return true;
fail:
    return false;
}