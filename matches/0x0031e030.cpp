namespace pure3d {
class pddiBaseContext {
public:
    char pad[0x58];
    void* member;
    int vfunc_69();
};
int pddiBaseContext::vfunc_69() { return *(int*)((char*)member + 0xc); }
}