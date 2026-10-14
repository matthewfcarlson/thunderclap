// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 11/12, incomplete)
// FUN_000df7b0 @ 0x000df7b0
struct Entry {
    int key;
    int value;
};
int __cdecl FUN_000f6610(int a);
class Table {
public:
    Entry entries[0x40];
    void FUN_000df7b0(int a, int b);
};
void Table::FUN_000df7b0(int a, int b) {
    int i = 0;
    while (i < 0x40 && entries[i].key != 0)
        i++;
    if (i < 0x40) {
        entries[i].key = FUN_000f6610(a);
        entries[i].value = b;
    }
}
