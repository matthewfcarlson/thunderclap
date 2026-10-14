extern const float zero_302e60;
struct Entry_302e60 {
    int* a;
    int* b;
    int c;
    float value;
    unsigned char active;
    char pad[3];
};
struct Range_302e60 {
    Entry_302e60* first;
    Entry_302e60* end;
};
struct Owner_302e60 {
    char pad0[4];
    Range_302e60* range;
    char pad8[0x28];
    int result;
    char pad34[8];
    float decrement;
    char Check(Entry_302e60*);
    void Update(int, int);
    void Run();
};
void Owner_302e60::Run() {
    Entry_302e60* p = range->first;
    Entry_302e60* e = range->end;
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