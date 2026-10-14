class Item {
    char pad[0x54];

  public:
    int key;
    void action(int a, int b);
};
void fallback(int a, int b);
class Owner {
    char pad[0x10];
    int count;
    Item** items;

  public:
    void run(int key, int a, int b);
};
void Owner::run(int key, int a, int b) {
    for (int i = 0; i < count; i++) {
        if (items[i] && items[i]->key == key) {
            items[i]->action(a, b);
            return;
        }
    }
    fallback(a, b);
}