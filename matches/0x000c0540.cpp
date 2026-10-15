extern "C" long __cdecl atol(const char*);
class Target {
  public:
    void action(const char*, long);
};
class Obj {
  public:
    char pad[4];
    Target* ptr;
    int Func(int n, const char** args);
};
int Obj::Func(int n, const char** args) {
    if (!ptr)
        return -1;
    if (n <= 0)
        return -1;
    const char* s = args[0];
    long v = 0;
    if (n > 1)
        v = atol(args[1]);
    ptr->action(s, v);
    return 0;
}