extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
class CScenarioManager_1ccf70 {
    char pad[0x1418];
    char names[4][32];

  public:
    void SetName(int i, const char* s);
};
void CScenarioManager_1ccf70::SetName(int i, const char* s) {
    if (i >= 0 && i < 4)
        strncpy(names[i], s, 32);
}