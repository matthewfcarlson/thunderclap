struct Item_ad580 {
    char pad[0x54];
    int id;
    int Do(int a, int b);
};
int Fallback(int a, int b);
class Manager_ad580 {
    char pad[0x10];
    int count;
    Item_ad580** items;

  public:
    int Run(int id, int a, int b);
};
int Manager_ad580::Run(int id, int a, int b) {
    int n = count;
    int i = 0;
    if (n > 0) {
        Item_ad580** arr = items;
        int key = id;
        Item_ad580** cur = arr;
        do {
            Item_ad580* p = *cur;
            if (p && p->id == key) {
                return arr[i]->Do(a, b);
            }
            ++i;
            ++cur;
        } while (i < n);
    }
    return Fallback(a, b);
}