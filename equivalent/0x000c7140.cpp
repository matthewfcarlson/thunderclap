// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000c7140 @ 0x000c7140
struct Temporary {
    char data[8];
    unsigned int FUN_0027af00();
    void FUN_0027af50();
};
struct ItemValue {
    void FUN_0027af70(unsigned int value);
    int unused;
};
struct Record {
    int status;
    int first;
    int second;
    int third;
    ItemValue value;
    int reserved;
    int fourth;
    int padding;
};
struct Manager {
    char padding[0x60];
    Record records[17];
    void FUN_000c7140(int index);
};
void Manager::FUN_000c7140(int index) {
    if (index >= 0 && index <= 16 && records[index].status != -1) {
        Temporary temporary;
        records[index].status = -1;
        unsigned int value = temporary.FUN_0027af00();
        records[index].value.FUN_0027af70(value);
        temporary.FUN_0027af50();
        records[index].first = 0;
        records[index].second = 0;
        records[index].third = 0;
        records[index].fourth = 0;
    }
}