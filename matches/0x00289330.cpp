class Item_289330 {
  public:
    virtual void v0(int);
    virtual void v1();
};
class Sub_289330 {
  public:
    void run();
};
class AnimationGroup {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    char pad[4];
    Sub_289330 sub;
    char pad2[8];
    unsigned int count;
    Item_289330** items;
    Item_289330* active;
};
void cleanup(void*);
void AnimationGroup::vfunc_1() {
    if (!active) {
        for (unsigned int i = 0; i < count; ++i) {
            Item_289330* it = items[i];
            if (it)
                it->v0(1);
        }
        cleanup(items);
        return;
    }
    sub.run();
    for (unsigned int j = 0; j < count; ++j)
        items[j]->v1();
    if (active) {
        active->v1();
        active = 0;
    }
}
