extern const float zero;
struct Entry {
    int* a;
    int* b;
    int c;
    float value;
    unsigned char active;
    char pad[3];
};
struct Range {
    Entry* first;
    Entry* end;
};
struct Owner {
    char pad0[4];
    Range* range;
    char pad8[0x28];
    int result;
    char pad34[8];
    float decrement;
    char Check(Entry*);
    void Update(int, int);
    void Run();
};
void Owner::Run() {
    Entry* p = range->first;
    Entry* e = range->end;
    while (p != e) {
        result = 0;
        if (p->active) {
            if (p->value <= 0.0f) {
                if (Check(p)) {
                    int x = *(int*)((char*)p->b + 0x20);
                    int y = *(int*)((char*)p->a + 0x20);
                    Update(y, x);
                    p->c = result;
                }
            } else
                p->value -= decrement;
        }
        e = range->end;
        ++p;
    }
}