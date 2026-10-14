class Item_adb90 {
  public:
    void F(void*, int);
};
class C_adb90 {
  public:
    char pad[0x10];
    int count;
    Item_adb90** items;
    char more[0x88];
    void F(int);
};
void C_adb90::F(int p) {
    int i = 0;
    if (count > 0) {
        do {
            items[i]->F((char*)this + 0xa0, p);
            ++i;
        } while (i < count);
    }
}