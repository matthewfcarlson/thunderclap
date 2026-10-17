struct Queue {
    char pad0[0x20];
    unsigned char count;
    char pad21[3];
    unsigned char* reverse;
    char pad28[8];
    unsigned char* entries;
    void FUN_00298810(unsigned char index);
};
void Queue::FUN_00298810(unsigned char index) {
    --count;
    unsigned char value = entries[index];
    reverse[value] = 0xff;
    if (count != index) {
        entries[index] = entries[count];
        reverse[entries[index]] = index;
    }
    entries[count] = 0xff;
}