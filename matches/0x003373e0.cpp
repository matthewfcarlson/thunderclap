extern "C" int strcmp(const char*, const char*);
class Table_3373e0 {
  public:
    int pad;
    int count;
    char first[1];
    char* Find(const char* s);
};
char* Table_3373e0::Find(const char* s) {
    for (int i = 0; i < count; i++) {
        char* e = first + 4 + i * 0x288;
        if (strcmp(s, e) == 0)
            return (char*)this + 8 + i * 0x288;
    }
    return 0;
}
