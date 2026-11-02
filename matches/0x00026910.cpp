extern "C" __int64 __cdecl Convert(int, int, int);
// b..d: a 3-word vector passed by value (FUN_000353d0 copies all three words).
struct Vec3_26910 {
    int x, y, z;
};
class Result {
  public:
    char Check(void*);
};
class Owner {
  public:
    Result* Find(__int64);
    char Test(int a, Vec3_26910 b);
};
char Owner::Test(int a, Vec3_26910 b) {
    __int64 key = Convert(a, 0, 0);
    Result* r = Find(key);
    if (!r)
        return 0;
    return r->Check(&b);
}