extern "C" int strcmp(const char*, const char*);
class K_b4c10 {
  public:
    char pad[0x26c];
    const char* names[128];
    bool Has(const char* s);
};
bool K_b4c10::Has(const char* s) {
    for (int i = 0; i < 128; i++) {
        const char* n = names[i];
        if (!n)
            break;
        if (strcmp(s, n) == 0)
            return true;
    }
    return false;
}
