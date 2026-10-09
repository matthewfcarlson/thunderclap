namespace pure3d {
struct BlendFrameController {
    char p[0x28];
    unsigned count;
    char q[4];
    struct Item {
        unsigned a, b;
        char r[0x24];
    } items[1];
    void vfunc_15(unsigned*, unsigned*);
};
void BlendFrameController::vfunc_15(unsigned* a, unsigned* b) {
    if (count > 0) {
        unsigned i = count - 1;
        *a = items[i].a;
        *b = items[i].b;
    } else {
        *a = 0;
        *b = 0;
    }
}
} // namespace pure3d