struct Result {
    char pad[0x324];
    int value;
};
unsigned __int64 __cdecl lookup(int, int, int);
class Owner {
  public:
    Result* resolve(unsigned __int64);
    int get(int);
};
int Owner::get(int id) {
    unsigned __int64 key = lookup(id, 0, 0);
    Result* p = resolve(key);
    if (!p)
        return 0;
    return p->value;
}