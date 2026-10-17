// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001ca830 @ 0x001ca830
struct Value { unsigned int word; void FUN_0027af50(); };
struct Record {
    unsigned int fields[12];
    Record* FUN_001ca830(Value first, unsigned int second, Value third, unsigned int fourth, unsigned int fifth, unsigned int sixth);
};
Record* Record::FUN_001ca830(Value first, unsigned int second, Value third, unsigned int fourth, unsigned int fifth, unsigned int sixth) {
    for (int i = 0; i < 12; ++i) fields[i] = 0;
    fields[7] = second;
    fields[6] = first.word;
    fields[8] = third.word;
    fields[10] = sixth;
    fields[0] = 0x30;
    fields[1] = 0x15;
    fields[9] = fourth;
    fields[4] = fifth;
    first.FUN_0027af50();
    third.FUN_0027af50();
    return this;
}