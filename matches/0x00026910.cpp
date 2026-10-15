extern "C" __int64 __cdecl Convert(int, int, int);
class Result {
  public:
    char Check(void*);
};
class Owner {
  public:
    Result* Find(__int64);
    char Test(int a, int b, int c, int d);
};
char Owner::Test(int a, int b, int c, int d) {
    __int64 key = Convert(a, 0, 0);
    Result* r = Find(key);
    if (!r)
        return 0;
    return r->Check(&b);
}