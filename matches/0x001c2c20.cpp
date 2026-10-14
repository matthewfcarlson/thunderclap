struct Entry_1c2c20 {
    int a, b, c;
    bool Check(const Entry_1c2c20*, unsigned);
};
class Obj_1c2c20 {
    char pad[0x180];

  public:
    unsigned count;
    void Add(const Entry_1c2c20* p);
};
void Obj_1c2c20::Add(const Entry_1c2c20* p) {
    for (unsigned i = 0; i < count; ++i) {
        if (((Entry_1c2c20*)this + i)->Check(p, 0x3727c5ac))
            return;
    }
    Entry_1c2c20* dst = (Entry_1c2c20*)this + count;
    ++count;
    *dst = *p;
}