extern void* g_vA[];
void operator delete(void*);
void operator delete[](void*);
class Condition_10e7c0 {
  public:
    void* vptr;
    void Fin();
};
class HulkActionLargestCondition_10e7c0 : public Condition_10e7c0 {
  public:
    char pad[0x10 - 4];
    void* m10;
    HulkActionLargestCondition_10e7c0* f5(unsigned char flags);
};
HulkActionLargestCondition_10e7c0* HulkActionLargestCondition_10e7c0::f5(unsigned char flags) {
    void* a = m10;
    vptr = g_vA;
    operator delete[](a);
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
