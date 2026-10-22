class Item {
  public:
    bool Set(int, int, int);
};
class CTriggerVolumeManager_1fdf50 {
    char pad[0x234];
    Item* items;

  public:
    int Find(int);
    bool Run(int id, int a, int b, int c);
};
bool CTriggerVolumeManager_1fdf50::Run(int id, int a, int b, int c) {
    int i = Find(id);
    if (i == -1)
        return false;
    return ((Item*)((char*)items + i * 0xc70))->Set(a, b, c);
}