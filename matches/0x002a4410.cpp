namespace pure3d {
struct Child {
    int a;
    int* first;
    int* last;
    int b;
};
class DrawableContainer {
    char pad[0x48];
    Child* begin;
    Child* end;

  public:
    int vfunc_16();
};
int DrawableContainer::vfunc_16() {
    int total = 0;
    unsigned count = (end - begin);
    for (unsigned i = 0; i < count; ++i)
        total += (int)(begin[i].last - begin[i].first);
    return total;
}
} // namespace pure3d