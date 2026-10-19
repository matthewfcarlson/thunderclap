class Obj {
  public:
    char pad[0x150];
    int value;
    int Check();
};
struct ThisWrap_001df2e0 {
    Obj* Find(int);
    int FUN_001df2e0(int key, int value);
};
int ThisWrap_001df2e0::FUN_001df2e0(int key, int value) {
    Obj* p = this->Find(key);
    if (!p || !p->Check())
        return -1;
    p->value = value;
    return 0;
}