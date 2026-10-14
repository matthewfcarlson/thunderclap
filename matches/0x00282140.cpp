class Item_282140 {
  public:
    virtual void F0();
    virtual void F1();
};
struct Entry_282140 {
    int id;
    char p[4];
    Item_282140* item;
    char tail[0x10];
};
class Owner_282140 {
  public:
    char pad[0x20];
    Entry_282140 entries[100];
    void Remove(int id);
};
void Owner_282140::Remove(int id) {
    int i = 0;
    while (entries[i].item == 0 || entries[i].id != id) {
        ++i;
        if (i >= 100)
            return;
    }
    if (entries[i].item) {
        entries[i].item->F1();
        entries[i].item = 0;
    }
}