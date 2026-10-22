struct Entry {
    char a[0x18];
    char* p;
    char b[6];
    short n;
    char c[4];
};
class CSPManager_1ddb80 {
  public:
    int Find(int);
    void Set(int, unsigned char);
    char pad[0x608];
    Entry entries[1];
};
void CSPManager_1ddb80::Set(int id, unsigned char v) {
    int i = Find(id);
    if (i >= 0) {
        Entry* e = &entries[i];
        int j = e->n + 0x104e;
        if (((char*)this)[j * 20] & 1) {
            char* p = e->p;
            if (p)
                p[0x1a1] = v;
        }
    }
}