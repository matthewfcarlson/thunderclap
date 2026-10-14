// Same code shape as 0x00044c00 (propagated; names are from that function)
struct Item_44c30 {
    void Do();
};
class X_44c30 {
  public:
    char pad[0x0c];
    int count;
    Item_44c30** items;
    bool Run();
};
bool X_44c30::Run() {
    int i;
    for (i = 0; i < count; ++i) {
        Item_44c30* p = items[i];
        if (p)
            p->Do();
    }
    return true;
}