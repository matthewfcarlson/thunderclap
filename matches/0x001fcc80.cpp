class Item;
class Helper {
  public:
    void Apply(Item*, int);
};
class Mid {
    char pad[12];

  public:
    Helper* helper;
};
class Obj {
    char pad[4];

  public:
    Mid* mid;
    Item* Find(int);
    void Run(int, int);
};
void Obj::Run(int a, int b) {
    Item* p = Find(a);
    if (p)
        mid->helper->Apply(p, b);
}