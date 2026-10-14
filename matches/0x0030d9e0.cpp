struct Object {
    void run();
};
struct Entry_30d9e0 {
    int a;
    int b;
    int key;
    int d;
    Object* object;
};
struct Container_30d9e0 {
    int pad;
    Entry_30d9e0* begin;
    Entry_30d9e0* end;
    void scan(int key);
};
void Container_30d9e0::scan(int key) {
    Entry_30d9e0* p = begin;
    if (p <= end) {
        do {
            if (p->a == key || p->key == key)
                p->object->run();
            Entry_30d9e0* last = end;
            Entry_30d9e0* old = p;
            p = (Entry_30d9e0*)((char*)p + 20);
            if (old == last)
                break;
        } while (1);
    }
}