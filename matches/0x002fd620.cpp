struct Inner_2fd620 {
    char pad[0x1fc];
    int* items;
};
class SimStateArticulated {
  public:
    char pad[0x70];
    Inner_2fd620* mThing;
    int vfunc_9(int);
};
int SimStateArticulated::vfunc_9(int index) {
    Inner_2fd620* p = mThing;
    if (index > 0 && p != 0 && p->items[index] == 0)
        p = 0;
    return (int)p;
}