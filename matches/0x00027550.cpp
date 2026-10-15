extern "C" unsigned __int64 __cdecl Find(unsigned int, int, int);
struct Item {
    char pad[0x1d20];
    float value;
};
class Obj {
  public:
    Item* Get(unsigned __int64);
    float Func(unsigned int);
};
float Obj::Func(unsigned int id) {
    unsigned __int64 v = Find(id, 0, 0);
    Item* p = Get(v);
    if (!p)
        return 1.0f;
    return p->value;
}