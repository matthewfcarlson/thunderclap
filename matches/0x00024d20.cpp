struct Result {
    char pad[0x1a4];
    int value;
};
class Provider {
  public:
    Result* Get(__int64);
};
class Owner {
  public:
    char pad[4];
    Provider* provider;
    int Fetch(int x);
};
extern __int64 __cdecl Convert(int);
int Owner::Fetch(int x) {
    Provider* p = provider;
    __int64 key = Convert(x);
    Result* r = p->Get(key);
    if (!r)
        return 0;
    return r->value;
}