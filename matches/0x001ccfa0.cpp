class CScenarioManager_1ccfa0 {
  public:
    char pad[0x1498];
    int a[4];
    int f(int i);
};
int CScenarioManager_1ccfa0::f(int i) {
    if (i >= 0 && i < 4)
        return a[i];
    return 0;
}