class Item {
  public:
    void Send(int, int, int);
};
class CTriggerVolumeManager_1fd920 {
    char pad[0x238];

  public:
    int count;
    Item* items[1];
    void Setup(int, int);
    void Run(int a, int b, int c);
};
void CTriggerVolumeManager_1fd920::Run(int a, int b, int c) {
    Setup(a, c);
    for (int i = 0; i < count; i++)
        items[i]->Send(b, 0, 0);
}