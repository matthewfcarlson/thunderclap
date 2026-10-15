class Item {
  public:
    virtual void Release(int);
};
extern "C" void __cdecl Free(void*);
void __cdecl FUN_00234810(Item*** list, int* refs) {
    if (--*refs == 0) {
        if ((*list)[0]) {
            for (int i = 0; (*list)[i]; ++i) {
                Item* p = (*list)[i];
                if (p)
                    p->Release(1);
            }
        }
        Free(*list);
        *list = 0;
    }
}