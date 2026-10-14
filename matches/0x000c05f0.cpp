extern "C" long __cdecl atol(const char*);
class Holder_c05f0 {
  public:
    void set(long);
};
class C_c05f0 {
  public:
    int pad;
    Holder_c05f0* value;
};
int __fastcall target(C_c05f0* self, int, int arg, const char** text) {
    if (self->value == 0)
        return -1;
    if (arg != 1)
        return -1;
    long n = atol(*text);
    self->value->set(n);
    return 0;
}
