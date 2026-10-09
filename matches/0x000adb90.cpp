class Item {
  public:
    void F(void*, int);
};
class C {
  public:
    char pad[0x10];
    int count;
    Item** items;
    char more[0x88];
    void F(int);
};
void C::F(int p) {
    int i = 0;
    if (count > 0) {
        do {
            items[i]->F((char*)this + 0xa0, p);
            ++i;
        } while (i < count);
    }
}