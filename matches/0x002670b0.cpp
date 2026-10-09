typedef unsigned int U;
struct Obj {
    virtual void F();
};
struct Entry {
    Obj* object;
    U field4;
    U field8;
    Entry* next;
};
extern Entry gEntries[45];
extern Entry gFallback;
void FUN_002670b0(int a, int b, Obj* obj) {
    Entry* dest = &gEntries[a];
    Entry* list;
    if (b == 45)
        list = &gFallback;
    else {
        list = &gEntries[b];
        if (list->next == 0)
            list = &gFallback;
    }
    obj->F();
    dest->object = obj;
    dest->next = list;
    dest->field4 = 0;
    dest->field8 = list->field4;
    list->field4 = (U)dest;
}
