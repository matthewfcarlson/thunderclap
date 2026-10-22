class CScenarioManager_1cc9b0 {
  public:
    char pad[0x10];
    void Set(int i, float v);
};
void CScenarioManager_1cc9b0::Set(int i, float v) {
    if (i >= 0 && i < 0x40)
        *(float*)((char*)this + i * 4 + 0x10) = v;
}
