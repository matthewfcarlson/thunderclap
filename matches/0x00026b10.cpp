extern "C" __int64 __cdecl lookup(int, int, int);
// b..d: a 3-word vector passed by value.
struct Vec3_26b10 {
    int x, y, z;
};
class Result {
  public:
    void Set(void*);
};
class Owner {
  public:
    Result* Find(__int64);
    void Action(int a, Vec3_26b10 b);
};
void Owner::Action(int a, Vec3_26b10 b) {
    __int64 id = lookup(a, 0, 0);
    Result* r = Find(id);
    if (r)
        r->Set(&b);
}