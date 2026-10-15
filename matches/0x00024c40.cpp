class Item {
    char pad[0x1a8];

  public:
    float value;
};
class Manager {
  public:
    Item* Find(unsigned long long);
};
extern "C" unsigned long long __cdecl Convert(int);
extern const float zero;
class Owner {
    char pad[4];
    Manager* mgr;

  public:
    float Get(int x);
};
float Owner::Get(int x) {
    Manager* m = mgr;
    unsigned long long v = Convert(x);
    Item* p = m->Find(v);
    if (!p)
        return zero;
    return p->value;
}