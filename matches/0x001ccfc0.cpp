class CScenarioManager_1ccfc0 {
  public:
    char pad[0x1498];
    int values[4];
    void Set(int index, int value);
};

void CScenarioManager_1ccfc0::Set(int index, int value) {
    if (index >= 0 && index < 4)
        values[index] = value;
}
