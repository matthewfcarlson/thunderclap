// STATUS: equivalent (tools/equiv.py level 3: 2979 inputs, branch coverage 4/4)
// FUN_000dd710 @ 0x000dd710
void *__cdecl FUN_0008d690(unsigned int size);

struct Block {
    int word[10];
};

class ControllerState {
public:
    virtual void v0();
    int a;                   // 0x04
    int b;                   // 0x08
    Block *first;            // 0x0c
    Block *second;           // 0x10
    ControllerState(int x, int y);
};

static Block *NewBlock() {
    Block *block = (Block *)FUN_0008d690(sizeof(Block));
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
