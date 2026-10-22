class Item;
class Helper {
  public:
    void Apply(Item*, int);
};
class Mid {
    char pad[12];

  public:
    Helper* helper;
};
class CTriggerVolumeManager_1fcc80 {
    char pad[4];

  public:
    Mid* mid;
    Item* Find(int);
    void Run(int, int);
};
void CTriggerVolumeManager_1fcc80::Run(int a, int b) {
    Item* p = Find(a);
    if (p)
        mid->helper->Apply(p, b);
}