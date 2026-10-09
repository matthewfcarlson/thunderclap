extern "C" long __cdecl atol(const char*);
class Holder {
  public:
    void set(long);
};
class C {
  public:
    int pad;
    Holder* value;
};
int __fastcall target(C* self, int, int arg, const char** text) {
    if (self->value == 0)
        return -1;
    if (arg != 1)
        return -1;
    long n = atol(*text);
    self->value->set(n);
    return 0;
}
