class CScenarioManager_1ccf50 {
    char pad[0x1418];

  public:
    int* f(int);
};
int* CScenarioManager_1ccf50::f(int x) {
    if (x >= 0 && x < 4)
        return (int*)((char*)this + x * 0x20 + 0x1418);
    return 0;
}