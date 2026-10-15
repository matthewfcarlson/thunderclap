struct Item {
    char pad[8];
    int kind;
};
struct Manager {
    char pad[0x44];
    int count;
    Item* Get(int);
};
class Obj {
  public:
    char pad[4];
    Manager* mgr;
    int* values;
    bool Fetch(int index, int* out);
};
bool Obj::Fetch(int index, int* out) {
    if (index < 0)
        return false;
    if (index >= mgr->count)
        return false;
    if (mgr->Get(index)->kind != 3)
        return false;
    *out = values[index];
    return true;
}