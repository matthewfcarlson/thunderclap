// STATUS: equivalent (tools/equiv.py level 3: 2978 inputs, branch coverage 6/6)
// FUN_00090630 @ 0x00090630
struct Text_90630 {
    unsigned int data;
    unsigned int size;
    Text_90630* FUN_0027b0e0(const char* s);
    void FUN_0027af70(Text_90630* other);
    void FUN_0027af50();
};
struct Entry_90630 {
    Text_90630 name;
    Text_90630 value;
    int fourth;
    int third;
    unsigned char spare;
    unsigned char enabled;
    char padding[30];
    int state;
    int fifth;
};
struct Table_90630 {
    Entry_90630 entries[50];
    int count;
    int FUN_00090050(const char* name);
    void FUN_00090630(const char* name, const char* value, int third, int fourth, int fifth, int sixth);
};
void Table_90630::FUN_00090630(const char* name, const char* value, int third, int fourth, int fifth, int sixth) {
    int index = FUN_00090050(name);
    if (index == -1) {
        index = count;
        if (index >= 50) return;
        Entry_90630& entry = entries[index];
        Text_90630 temp;
        entry.name.FUN_0027af70(temp.FUN_0027b0e0(name));
        temp.FUN_0027af50();
        entry.value.FUN_0027af70(temp.FUN_0027b0e0(value));
        temp.FUN_0027af50();
        ++count;
        entry.state = 0;
        entry.fifth = fifth;
    }
    Entry_90630& entry = entries[index];
    entry.enabled = sixth == 1;
    entry.third = third;
    entry.fourth = fourth;
}
