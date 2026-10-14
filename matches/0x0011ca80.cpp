struct ObjC_11ca80 {
    char pad[0x10];
    void* next;
};
struct ObjA_11ca80 {
    char pad[0x1c];
    float value;
    ObjC_11ca80* step();
};
struct ObjB_11ca80 {
    char pad[0x10];
    void* child;
    ObjA_11ca80* get();
};
struct Child_11ca80 {
    void run(void*);
};
struct RoutAction {
    char pad[0x34];
    ObjA_11ca80* p34;
    ObjB_11ca80* p38;
    char pad2[0x20];
    void* p5c;
    char pad3[0x10];
    float p70;
    bool vfunc_3(int, int);
};
bool RoutAction::vfunc_3(int a, int b) {
    ObjA_11ca80* x = p38->get();
    ObjC_11ca80* y = x->step();
    p5c = y;
    float f = p34->value;
    p70 = f * f;
    ((Child_11ca80*)y->next)->run((char*)this + 0x28);
    return true;
}