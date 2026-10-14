class Item_1cacc0 {
  public:
    bool Check();
    void Set(const char*, int);
    void Finish();
};
Item_1cacc0* GetItem();
class Owner_1cacc0 {
  public:
    char pad[0x14];
    int oldValue;
    int newValue;
    bool Run();
};
bool Owner_1cacc0::Run() {
    Item_1cacc0* item = GetItem();
    if (!item)
        return false;
    if (!item->Check())
        return false;
    item->Set("old", oldValue);
    item->Set("new", newValue);
    item->Finish();
    return true;
}