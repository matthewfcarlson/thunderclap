// STATUS: equivalent (tools/equiv.py level 3: 167 inputs, branch coverage 11/12, incomplete)
// FUN_0027d6c0 @ 0x0027d6c0
struct Object {
    virtual void slot0();
    virtual void release();
};
struct Entry_27d6c0 {
    Object* object;
    unsigned int state;
    unsigned int extra;
};
struct Container_27d6c0 {
    char padding[0xb4];
    int count;
    Entry_27d6c0 entries[1];
    bool remove(Object* object);
};
bool Container_27d6c0::remove(Object* object) {
    if (!object) return false;
    int index;
    for (index = 0; index < count; ++index) {
        if (entries[index].object == object) break;
    }
    if (index >= count) return false;
    Entry_27d6c0& entry = entries[index];
    entry.state = 0;
    if (entry.object) {
        entry.object->release();
        entry.object = 0;
    }
    int last = count - 1;
    count = last;
    if (index < last) {
        entry.object = entries[last].object;
        entry.state = entries[last].state;
        entry.extra = entries[last].extra;
        entries[count].object = 0;
        entries[count].state = 0;
    }
    return true;
}
