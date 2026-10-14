extern "C" int HashName(const char*);
class Registry_329320 {
  public:
    char pad0[4];
    unsigned int count;
    char pad8[4];
    void Add(const char*, unsigned int);
};
void Registry_329320::Add(const char* name, unsigned int value) {
    int hash = HashName(name);
    unsigned int i = 0;
    while (i < count) {
        if (*(int*)((char*)this + 8 + i * 0x30c) == hash)
            return;
        ++i;
    }
    unsigned int h = 0;
    const char* p = name;
    while (*p) {
        h = h * 16 + (int)*p;
        ++p;
        unsigned int x = h & 0xf0000000;
        if (x)
            h ^= (x >> 24) ^ x;
    }
    *(unsigned int*)((char*)this + 8 + count * 0x30c) = h;
    *(unsigned int*)((char*)this + 12 + count * 0x30c) = value;
    *(unsigned int*)((char*)this + 16 + count * 0x30c) = 0;
    ++count;
}