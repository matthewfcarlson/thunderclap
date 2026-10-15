class Obj {
  public:
    char pad[0x150];
    int value;
    int Check();
};
extern "C" Obj* __stdcall Find(int);
int __stdcall FUN_001df2e0(int key, int value) {
    Obj* p = Find(key);
    if (!p || !p->Check())
        return -1;
    p->value = value;
    return 0;
}