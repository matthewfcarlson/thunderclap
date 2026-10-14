class Helper_14ee00 {
  public:
    void* first();
    void* second();
};
class InterruptAccumulatorSetAction {
  public:
    char pad[0x1c];
    void* field1c;
    Helper_14ee00* field20;
    bool vfunc_3(void*, void*);
};
bool InterruptAccumulatorSetAction::vfunc_3(void*, void*) {
    Helper_14ee00* h = field20;
    void* a = h->first();
    void* b = ((Helper_14ee00*)a)->second();
    *(int*)((char*)b + 0x320) = *(int*)((char*)field1c + 0x10);
    return false;
}
