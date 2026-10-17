// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002b1160 @ 0x002b1160
struct State { unsigned int values[6]; };
struct Handler {
    void FUN_002b1070(unsigned int value, State* state);
    void FUN_002b1160(unsigned int value);
};
void Handler::FUN_002b1160(unsigned int value) {
    State state = {{0, 0, 0, 0, 0, 0}};
    FUN_002b1070(value, &state);
}