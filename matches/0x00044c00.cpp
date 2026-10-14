struct Item_44c00 {
    void Do();
};
class X_44c00 {
  public:
    char pad[0x0c];
    int count;
    Item_44c00** items;
    bool Run();
};
bool X_44c00::Run() {
    int i;
    for (i = 0; i < count; ++i) {
        Item_44c00* p = items[i];
        if (p)
            p->Do();
    }
    return true;
}