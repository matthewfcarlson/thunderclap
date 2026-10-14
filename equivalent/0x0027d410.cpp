// STATUS: equivalent (tools/equiv.py level 3: 170 inputs, branch coverage 8/8)
// FUN_0027d410 @ 0x0027d410
struct Key_27d410 { char pad[8]; unsigned int a; unsigned int b; };
struct KeyList_27d410 { char pad[0x1c]; Key_27d410** begin; Key_27d410** end; };
struct Selector_27d410 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void Select(int index, int flag);
    char pad[0x98 - 4];
    KeyList_27d410* list;
    void FUN_0027d410(const unsigned int* id);
};

void Selector_27d410::FUN_0027d410(const unsigned int* id) {
    int index = -1;
    int n = list->end - list->begin;
    unsigned int a = id[0];
    unsigned int b = id[1];
    Key_27d410** it = list->begin;
    for (int i = 0; i < n; ++i, ++it) {
        if ((*it)->a == a && (*it)->b == b) {
            index = i;
            break;
        }
    }
    Select(index, 1);
}
