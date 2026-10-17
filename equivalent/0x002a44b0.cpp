// STATUS: equivalent (tools/equiv.py level 3: 632 inputs, branch coverage 6/6)
// pure3d::DrawableContainer::vfunc_18 @ 0x002a44b0
namespace pure3d {
struct DrawableContainer {
    char pad[0x48];
    struct Group { unsigned unknown; void **begin; void **end; unsigned spare; };
    Group *groupsBegin;
    Group *groupsEnd;
    void *vfunc_18(unsigned index);
};
void *DrawableContainer::vfunc_18(unsigned index) {
    unsigned groupCount = (unsigned)(((int)groupsEnd - (int)groupsBegin) >> 4);
    Group *group = groupsBegin;
    for (unsigned i = 0; i < groupCount; ++i, ++group) {
        unsigned count = (unsigned)(((int)group->end - (int)group->begin) >> 2);
        if (index < count) return group->begin[index];
        index -= count;
    }
    return 0;
}
}