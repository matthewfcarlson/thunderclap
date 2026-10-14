struct Entry {
    int a, b, c;
    bool Check(const Entry*, unsigned);
};
class Obj {
    char pad[0x180];

  public:
    unsigned count;
    void Add(const Entry* p);
};
void Obj::Add(const Entry* p) {
    for (unsigned i = 0; i < count; ++i) {
        if (((Entry*)this + i)->Check(p, 0x3727c5ac))
            return;
    }
    Entry* dst = (Entry*)this + count;
    ++count;
    *dst = *p;
}