class Helper {
  public:
    void* first();
    void* second();
};
class InterruptAccumulatorSetAction {
  public:
    char pad[0x1c];
    void* field1c;
    Helper* field20;
    bool vfunc_3(void*, void*);
};
bool InterruptAccumulatorSetAction::vfunc_3(void*, void*) {
    Helper* h = field20;
    void* a = h->first();
    void* b = ((Helper*)a)->second();
    *(int*)((char*)b + 0x320) = *(int*)((char*)field1c + 0x10);
    return false;
}
