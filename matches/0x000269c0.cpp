typedef __int64 i64;
extern "C" i64 __cdecl Lookup(int a, int b, int c);
class Result {
  public:
    void Apply(int);
};
class Owner {
  public:
    Result* Select(i64);
    void Do(int, int);
};
void Owner::Do(int a, int b) {
    Result* r = Select(Lookup(a, 0, 0));
    r->Apply(b);
}