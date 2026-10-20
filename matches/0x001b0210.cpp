struct AgentState {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual int vfunc_6();
};
struct Checker {
    unsigned char FUN_001d7300();
};
struct Object {
    char pad[8];
    Checker* check;
    int kind;
};
struct Input {
    char pad[0x18];
    Object* object;
    char pad2[4];
    AgentState* state;
};
struct AICollisionSolverAgent {
    unsigned char vfunc_11(Input* input);
};
unsigned char AICollisionSolverAgent::vfunc_11(Input* input) {
    unsigned char result = 1;
    AgentState* state = input->state;
    if (state) {
        int value = state->vfunc_6();
        result = (value == 0 || value == 8) ? 0 : result;
    }
    if (input->object->kind == 5 && !input->object->check->FUN_001d7300())
        return 0;
    return result;
}