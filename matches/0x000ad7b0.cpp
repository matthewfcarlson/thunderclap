class Item_ad7b0 {
    char pad[0x54];

  public:
    int key;
    void action(int a, int b);
};
void fallback(int a, int b);
class Owner_ad7b0 {
    char pad[0x10];
    int count;
    Item_ad7b0** items;

  public:
    void run(int key, int a, int b);
};
void Owner_ad7b0::run(int key, int a, int b) {
    for (int i = 0; i < count; i++) {
        if (items[i] && items[i]->key == key) {
            items[i]->action(a, b);
            return;
        }
    }
    fallback(a, b);
}