struct Item {
    short id;
    char pad[0x54];
};
class Obj {
    char pad[0x58c];
    Item* items;
    char pad2[4];
    int count;

  public:
    int Find(int id);
};
int Obj::Find(int id) {
    int n = 0;
    for (int i = 0; i < count; i++)
        if (items[i].id == id)
            ++n;
    return n;
}