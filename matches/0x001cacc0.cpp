class Item {
  public:
    bool Check();
    void Set(const char*, int);
    void Finish();
};
Item* GetItem();
class Owner {
  public:
    char pad[0x14];
    int oldValue;
    int newValue;
    bool Run();
};
bool Owner::Run() {
    Item* item = GetItem();
    if (!item)
        return false;
    if (!item->Check())
        return false;
    item->Set("old", oldValue);
    item->Set("new", newValue);
    item->Finish();
    return true;
}