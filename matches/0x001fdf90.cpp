class CTriggerVolumeManager_1fdf90 {
  public:
    char pad[0x234];
    char* data;
    int GetIndex(int);
    void* Lookup(int);
};
void* CTriggerVolumeManager_1fdf90::Lookup(int x) {
    int i = GetIndex(x);
    if (i == -1)
        return 0;
    return *(void**)(data + i * 0xc70 + 0x6e0);
}