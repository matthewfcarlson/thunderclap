class Item {
  public:
    void Act();
    char pad[0xc70];
};
struct This_Lookup {
    int Lookup(int);
};
class Obj {
    char pad[0x234];
    Item* items;

  public:
    bool Go(int);
};
bool Obj::Go(int id) {
    int i = ((This_Lookup*)this)->Lookup(id);
    if (i == -1)
        return false;
    items[i].Act();
    return true;
}