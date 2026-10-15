extern "C" __int64 __cdecl lookup(int, int, int);
class Result {
  public:
    void Set(void*);
};
class Owner {
  public:
    Result* Find(__int64);
    void Action(int a, int b, int c, int d);
};
void Owner::Action(int a, int b, int c, int d) {
    __int64 id = lookup(a, 0, 0);
    Result* r = Find(id);
    if (r)
        r->Set(&b);
}