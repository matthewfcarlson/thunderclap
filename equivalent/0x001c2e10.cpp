// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001c2e10 @ 0x001c2e10
struct Input { int value; int next; };
struct Object {
    int value;
    void FUN_001c2770(int value, int* next);
    Object* FUN_001c2e10(Input* input);
};
Object* Object::FUN_001c2e10(Input* input) {
    value = 0;
    FUN_001c2770(input->value, &input->next);
    return this;
}
