extern "C" long __cdecl atol(const char*);
class H {
  public:
    void Go(long);
};
class C {
  public:
    char pad[4];
    H* field;
    int F(int, char**);
};
int C::F(int p, char** q) {
    if (field == 0)
        return -1;
    if (p != 1)
        return -1;
    if (*q != 0) {
        long v = atol(*q);
        field->Go(v);
    }
    return 0;
}