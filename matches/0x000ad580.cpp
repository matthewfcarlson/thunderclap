struct Item {
    char pad[0x54];
    int id;
    void Do(int a, int b);
};
void Fallback(int a, int b);
class Manager {
    char pad[0x10];
    int count;
    Item** items;

  public:
    void Run(int id, int a, int b);
};
void Manager::Run(int id, int a, int b) {
    int n = count;
    int i = 0;
    if (n > 0) {
        Item** arr = items;
        int key = id;
        Item** cur = arr;
        do {
            Item* p = *cur;
            if (p && p->id == key) {
                arr[i]->Do(a, b);
                return;
            }
            ++i;
            ++cur;
        } while (i < n);
    }
    Fallback(a, b);
}