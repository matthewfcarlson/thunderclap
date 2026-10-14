struct Controller {
    void FUN_002fc670(int);
};
struct Object {
    virtual void AddRef();
    virtual void Release();
    char pad[0x9c];
    Controller* controller;
};
struct Entry {
    Object* object;
    void* data;
    unsigned flags;
};
struct Owner {
    char pad[0xb4];
    int count;
    Entry entries[4];
    void FUN_0027e780(Object*, void*);
    bool FUN_0027ed90(Object*, void*, unsigned);
};
bool Owner::FUN_0027ed90(Object* object, void* data, unsigned flags) {
    if (!object || !data || count >= 4)
        return false;
    if (flags & 4) {
        if (object->controller)
            object->controller->FUN_002fc670(2);
        FUN_0027e780(object, data);
    }
    Entry* entry = &entries[count];
    object->AddRef();
    if (entry->object)
        entry->object->Release();
    entry->object = object;
    entries[count].data = data;
    entries[count].flags = flags;
    ++count;
    return true;
}
