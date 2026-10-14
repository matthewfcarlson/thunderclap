class Item_1c5fb0 {
  public:
    char pad[8];
};
class Checker_1c5fb0 {
  public:
    bool test(void*);
};
class Owner_1c5fb0 {
  public:
    char pad0[4];
    Item_1c5fb0** items;
    unsigned int count;
    int Find(Checker_1c5fb0*);
};
int Owner_1c5fb0::Find(Checker_1c5fb0* arg) {
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
