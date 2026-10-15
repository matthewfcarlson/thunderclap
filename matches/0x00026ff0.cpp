typedef unsigned __int64 U64;
struct Result {
    char pad[0x1ca0];
    struct Thing* thing;
};
struct Thing {
    void Act(int);
};
U64 __cdecl Lookup(int, int, int);
class Owner {
  public:
    Result* Resolve(U64);
    void Run(int key, int value);
};
void Owner::Run(int key, int value) {
    U64 id = Lookup(key, 0, 0);
    Result* r = Resolve(id);
    if (r && r->thing)
        r->thing->Act(value);
}
