typedef unsigned int U_2670b0;
struct Obj_2670b0 {
    virtual void F();
};
struct Entry_2670b0 {
    Obj_2670b0* object;
    U_2670b0 field4;
    U_2670b0 field8;
    Entry_2670b0* next;
};
extern Entry_2670b0 gEntries_2670b0[45];
extern Entry_2670b0 gFallback_2670b0;
void FUN_002670b0(int a, int b, Obj_2670b0* obj) {
    Entry_2670b0* dest = &gEntries_2670b0[a];
    Entry_2670b0* list;
    if (b == 45)
        list = &gFallback_2670b0;
    else {
        list = &gEntries_2670b0[b];
        if (list->next == 0)
            list = &gFallback_2670b0;
    }
    obj->F();
    dest->object = obj;
    dest->next = list;
    dest->field4 = 0;
    dest->field8 = list->field4;
    list->field4 = (U_2670b0)dest;
}
