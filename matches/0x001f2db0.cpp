extern int g_size_1f2db0;
class Checker_1f2db0 {
  public:
    bool check(int);
};
extern Checker_1f2db0* g_checker;
int __cdecl make_stream(int, int);
int __cdecl create_stream(int, int, int, int, int, int, int);
class StreamPlayerAllocator {
  public:
    virtual int vfunc_0(int, int, int, int);
    virtual int vfunc_1();
};
class CSoundStreamAllocator : public StreamPlayerAllocator {
  public:
    int vfunc_0(int, int, int, int);
};
int CSoundStreamAllocator::vfunc_0(int a, int b, int c, int d) {
    int x = make_stream(d, g_size_1f2db0);
    if (!g_checker->check(x))
        return 0;
    return create_stream(c, 0, b, x, 0, 0, 1);
}