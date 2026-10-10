// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 4/4)
// FUN_0026e240 @ 0x0026e240
struct Item { unsigned int words[7]; };
struct Queue {
    char pad[0xac];
    Item items[256];
    unsigned int writeIndex;
    unsigned int readIndex;
    void FUN_0026e240(const Item *item);
};
void Queue::FUN_0026e240(const Item *item) {
    unsigned int index = writeIndex;
    if (index == 255 ? readIndex == 0 : readIndex - index == 1)
        return;
    items[index] = *item;
    writeIndex = (writeIndex + 1) & 255;
}