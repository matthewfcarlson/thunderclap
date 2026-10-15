class Item {
  public:
    void Apply(int);
};
class Host {
  public:
    Item* Lookup(__int64);
    void Act(const char*, int);
};
extern "C" __int64 __cdecl Convert(const char*, int, int);
void Host::Act(const char* s, int n) {
    __int64 k = Convert(s, 0, 0);
    Item* p = Lookup(k);
    if (p)
        p->Apply(n);
}