struct Controller_27ed90 {
    void FUN_002fc670(int);
};
struct Object {
    virtual void AddRef();
    virtual void Release();
    char pad[0x9c];
    Controller_27ed90* controller;
};
struct Entry_27ed90 {
    Object* object;
    void* data;
    unsigned flags;
};
struct Owner_27ed90 {
    char pad[0xb4];
    int count;
    Entry_27ed90 entries[4];
    void FUN_0027e780(Object*, void*);
    bool FUN_0027ed90(Object*, void*, unsigned);
};
bool Owner_27ed90::FUN_0027ed90(Object* object, void* data, unsigned flags) {
    if (!object || !data || count >= 4)
        return false;
    if (flags & 4) {
        if (object->controller)
            object->controller->FUN_002fc670(2);
        FUN_0027e780(object, data);
    }
    Entry_27ed90* entry = &entries[count];
    object->AddRef();
    if (entry->object)
        entry->object->Release();
    entry->object = object;
    entries[count].data = data;
    entries[count].flags = flags;
    ++count;
    return true;
}
