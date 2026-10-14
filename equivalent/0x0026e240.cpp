// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 4/4)
// FUN_0026e240 @ 0x0026e240
struct Item_26e240 { unsigned int words[7]; };
struct Queue_26e240 {
    char pad[0xac];
    Item_26e240 items[256];
    unsigned int writeIndex;
    unsigned int readIndex;
    void FUN_0026e240(const Item_26e240 *item);
};
void Queue_26e240::FUN_0026e240(const Item_26e240 *item) {
    unsigned int index = writeIndex;
    if (index == 255 ? readIndex == 0 : readIndex - index == 1)
        return;
    items[index] = *item;
    writeIndex = (writeIndex + 1) & 255;
}