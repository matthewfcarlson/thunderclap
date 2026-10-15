class Item {
  public:
    Item* Act();
};
class Owner {
  public:
    Item* Run(int);
    Item* Find(unsigned __int64);
};
extern "C" unsigned __int64 __cdecl Make(int, int, int);
Item* Owner::Run(int x) {
    unsigned __int64 v = Make(x, 0, 0);
    Item* p = Find(v);
    if (!p)
        return p;
    return p->Act();
}