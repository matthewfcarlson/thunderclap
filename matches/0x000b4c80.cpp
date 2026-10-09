extern "C" int __cdecl strcmp(const char*, const char*);
class Table {
  public:
    bool Has(const char* name);
    char pad[0x6c];
    const char* names[0x80];
};
bool Table::Has(const char* name) {
    for (int i = 0; i < 0x80; i++) {
        const char* s = names[i];
        if (!s)
            return false;
        if (strcmp(name, s) == 0)
            return true;
    }
    return false;
}
