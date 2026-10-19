namespace pure3d {
struct ShadowSkin {
    char pad[0x48];
    struct Link {
        struct Value {
            void FUN_002b57a0(int);
        }* value;
    }* link;
    void vfunc_10(int);
};
} // namespace pure3d
void pure3d::ShadowSkin::vfunc_10(int a0) {
    link->value->FUN_002b57a0(a0);
}