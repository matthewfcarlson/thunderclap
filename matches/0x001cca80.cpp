class CScenarioManager_1cca80 {
  public:
    char pad[0x214];
    void Remove(int id);
};
void CScenarioManager_1cca80::Remove(int id) {
    int i;
    for (i = 0; i < 16; ++i) {
        if (*(int*)((char*)this + 0x214 + i * 0x108) == id) {
            char* p = (char*)this + 0x110 + i * 0x108;
            *(int*)p = (int)0xbf800000;
            p[4] = 0;
            *(int*)(p + 0x104) = -1;
            return;
        }
    }
}