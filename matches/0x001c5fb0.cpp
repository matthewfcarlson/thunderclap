class Item {
  public:
    char pad[8];
};
class Checker {
  public:
    bool test(void*);
};
class Owner {
  public:
    char pad0[4];
    Item** items;
    unsigned int count;
    int Find(Checker*);
};
int Owner::Find(Checker* arg) {
    unsigned int i = 0;
    if (count > 0) {
        do {
            if (arg->test((char*)items[i] + 8))
                return (int)items[i];
            ++i;
        } while (i < count);
    }
    return 0;
}
