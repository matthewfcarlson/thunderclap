// STATUS: equivalent (tools/equiv.py level 3: 2979 inputs, branch coverage 4/4)
// FUN_000dd710 @ 0x000dd710
void *__cdecl FUN_0008d690(unsigned int size);

struct Block_dd710 {
    int word[10];
};

class ControllerState {
public:
    virtual void v0();
    int a;                   // 0x04
    int b;                   // 0x08
    Block_dd710 *first;            // 0x0c
    Block_dd710 *second;           // 0x10
    ControllerState(int x, int y);
};

static Block_dd710 *NewBlock() {
    Block_dd710 *block = (Block_dd710 *)FUN_0008d690(sizeof(Block_dd710));
    if (block) {
        for (int i = 0; i < 10; i++)
            block->word[i] = 0;
    }
    return block;
}

ControllerState::ControllerState(int x, int y) {
    a = y;
    b = x;
    first = NewBlock();
    second = NewBlock();
}
