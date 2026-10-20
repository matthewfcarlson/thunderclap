#include "compat/ptr.h"
#include "gen/pure3d.h"

struct Item_2a4150 {
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
struct Group_2a4150 {
    unsigned unknown;
    Item_2a4150** begin;
    Item_2a4150** end;
    unsigned capacity;
};
namespace pure3d {

} // namespace pure3d
char pure3d::DrawableContainer::vfunc_7() {
    unsigned count = (unsigned)(((hulk_intptr)(*(Group_2a4150 * *)&this->f_4c) - (hulk_intptr)(*(Group_2a4150 * *)&this->f_48)) >> 4);
    for (unsigned i = 0; i < count; ++i) {
        Group_2a4150* group = (*(Group_2a4150 * *)&this->f_48) + i;
        unsigned items = (unsigned)(((hulk_intptr)group->end - (hulk_intptr)group->begin) >> 2);
        for (unsigned j = 0; j < items; ++j) {
            Item_2a4150* item = group->begin[j];
            if (item && !item->slot22())
                return (char)(false);
        }
    }
    return (char)(true);
}
