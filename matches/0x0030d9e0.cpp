struct Object { void run(); };
struct Entry { int a; int b; int key; int d; Object* object; };
struct Container { int pad; Entry* begin; Entry* end; void scan(int key); };
void Container::scan(int key) {
    Entry* p = begin;
    if (p <= end) {
        do {
            if (p->a == key || p->key == key) p->object->run();
            Entry* last = end;
            Entry* old = p;
            p = (Entry*)((char*)p + 20);
            if (old == last) break;
        } while (1);
    }
}