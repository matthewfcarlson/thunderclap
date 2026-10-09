struct ObjC {
    char pad[0x10];
    void* next;
};
struct ObjA {
    char pad[0x1c];
    float value;
    ObjC* step();
};
struct ObjB {
    char pad[0x10];
    void* child;
    ObjA* get();
};
struct Child {
    void run(void*);
};
struct RoutAction {
    char pad[0x34];
    ObjA* p34;
    ObjB* p38;
    char pad2[0x20];
    void* p5c;
    char pad3[0x10];
    float p70;
    bool vfunc_3(int, int);
};
bool RoutAction::vfunc_3(int a, int b) {
    ObjA* x = p38->get();
    ObjC* y = x->step();
    p5c = y;
    float f = p34->value;
    p70 = f * f;
    ((Child*)y->next)->run((char*)this + 0x28);
    return true;
}