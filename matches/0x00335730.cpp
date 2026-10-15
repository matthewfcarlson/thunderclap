struct Entry {
    int a, b;
};
struct Item {
    char pad[8];
    int type;
};
class Owner {
  public:
    char pad[0x44];
    int count;
    Item* Get(int);
};
class Target {
  public:
    char pad[4];
    Owner* owner;
    Entry** entries;
    bool Fetch(int index, int* outA, int* outB);
};
bool Target::Fetch(int index, int* outA, int* outB) {
    if (index < 0)
        return false;
    if (index >= owner->count)
        return false;
    Item* item = owner->Get(index);
    if (item->type != 7)
        return false;
    Entry* e = entries[index];
    *outA = e->a;
    *outB = e->b;
    return true;
}