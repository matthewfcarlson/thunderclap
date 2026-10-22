extern "C" void CopyBytes(void*, const void*, unsigned int);
class CScenarioManager_1cce60 {
    char pad[0x13f8];
    char buf[32];

  public:
    void Copy(const void* p);
};
void CScenarioManager_1cce60::Copy(const void* p) {
    CopyBytes(buf, p, 32);
}