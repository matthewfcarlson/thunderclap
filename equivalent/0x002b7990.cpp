// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// pure3d::PolySkin::vfunc_17 @ 0x002b7990
namespace pure3d {
struct Item { char pad[8]; int first; int second; };
struct DrawableContainer { void vfunc_17(int, int); };
struct PolySkin : DrawableContainer {
    char pad[0x6c - sizeof(DrawableContainer)];
    Item* primary;
    Item* secondary;
    void vfunc_17(int first, int second);
};
void PolySkin::vfunc_17(int first, int second) {
    if ((!primary || primary->first != first || primary->second != second) &&
        (!secondary || secondary->first != first || secondary->second != second))
        DrawableContainer::vfunc_17(first, second);
}
}