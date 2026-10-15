struct Elem {
    char pad[16];
    void update(void*);
};
class Obj {
  public:
    char pad[12];
    unsigned count;
    Elem* elems;
    char* data;
    char pad2[10];
    char dirty;
    char ready;
    void run(int);
};
void Obj::run(int) {
    if (dirty) {
        for (unsigned i = 0; i < count; ++i)
            elems[i].update(data + i * 64);
        dirty = 0;
        ready = 1;
    }
}