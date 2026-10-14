struct Item {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual bool slot22();
};
struct Group {
    unsigned unknown;
    Item** begin;
    Item** end;
    unsigned capacity;
};
namespace pure3d {
struct DrawableContainer {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7();
    char padding[0x44];
    Group* groupsBegin;
    Group* groupsEnd;
};
bool DrawableContainer::vfunc_7() {
    unsigned count = (unsigned)(((int)groupsEnd - (int)groupsBegin) >> 4);
    for (unsigned i = 0; i < count; ++i) {
        Group* group = groupsBegin + i;
        unsigned items = (unsigned)(((int)group->end - (int)group->begin) >> 2);
        for (unsigned j = 0; j < items; ++j) {
            Item* item = group->begin[j];
            if (item && !item->slot22())
                return false;
        }
    }
    return true;
}
} // namespace pure3d
