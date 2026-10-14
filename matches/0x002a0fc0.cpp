class Item_2a0fc0 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_2a0fc0 {
  public:
    char pad[0x18];
    Item_2a0fc0** items;
    void Set(int index, Item_2a0fc0* value);
};
void Owner_2a0fc0::Set(int index, Item_2a0fc0* value) {
    Item_2a0fc0** p = items + index;
    if (value)
        value->First();
    if (*p)
        (*p)->Second();
    *p = value;
}