class Item {
  public:
    char Valid();
    int Value();
};
class Owner {
  public:
    char Do(int, int);
    char Run(int x, Item* p);
};
char Owner::Run(int x, Item* p) {
    char ok = p->Valid();
    if (!ok)
        return ok;
    return Do(x, p->Value());
}