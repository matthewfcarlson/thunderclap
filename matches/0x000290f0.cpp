class Actor {
  public:
    void Act(int, int);
};
struct Result {
    char pad[0x1ca0];
    Actor* ptr;
};
struct Inner {
    char pad[0x12c];
    int val;
};
class Obj {
  public:
    char pad[0x124];
    Inner* inner;
    Result* Find(__int64);
    void Target(void*);
};
extern "C" __int64 __cdecl Fetch(void*, int, int);
void Obj::Target(void* p) {
    Result* r = Find(Fetch(p, 0, 0));
    if (r != 0 && r->ptr != 0 && inner != 0)
        r->ptr->Act(inner->val, 0);
}