namespace hulkfight {
namespace scenario {
class EventCondition;
}
} // namespace hulkfight
struct Result {
    char pad[4];
    int id;
};
struct Obj {
    Result* get();
};
extern "C" Obj* __cdecl cast(void*, int, void*, void*, int);
extern int desc1, desc2;
namespace hulkfight {
namespace scenario {
class EventCondition {
  public:
    char pad[12];
    int id;
    char vfunc_6(int a, void* b, int c);
};
char EventCondition::vfunc_6(int a, void* b, int c) {
    Obj* p = cast(b, 0, &desc1, &desc2, 0);
    if (!p)
        return false;
    return p->get()->id == id;
}
} // namespace scenario
} // namespace hulkfight