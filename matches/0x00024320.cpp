class ItemList {
  public:
    int pad0[3];
    int count;
    int values[17];
    int field54[16];
    int field94[16];
    bool Remove(int index);
};
bool ItemList::Remove(int index) {
    if (index < 0 || index >= count)
        return false;
    --count;
    values[index] = 0;
    if (count > 0) {
        values[index] = values[count];
        values[count] = 0;
        field54[index] = field54[count];
        field94[index] = field94[count];
    }
    return true;
}