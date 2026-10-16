struct Thing {
    char pad[0x74];
    void* item;
};
class Manager {
  public:
    void Act(void*);
};
class Obj {
  public:
    char pad[8];
    Manager* mgr;
    bool Test(Thing* t);
};
bool Obj::Test(Thing* t) {
    bool result = true;
    if (t->item)
        mgr->Act(t->item);
    else
        result = false;
    return result;
}