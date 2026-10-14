extern "C" int strcmp(const char*, const char*);
class Table_f8cc0 {
  public:
    int pad;
    int items[129];
    int Find(const char* s);
};
int Table_f8cc0::Find(const char* s) {
    int i = 0;
    const char* p = s;
    do {
        if (items[i] == 0)
            return 0;
        if (strcmp((const char*)(items[i] + 0x18), p) == 0)
            return ((int*)this)[i + 1];
        ++i;
    } while (i < 128);
    return 0;
}