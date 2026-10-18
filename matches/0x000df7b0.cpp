// FUN_000df7b0 @ 0x000df7b0
struct Entry_df7b0 {
    int key;
    int value;
};
int __cdecl FUN_000f6610(int a);
class Table_df7b0 {
public:
    Entry_df7b0 entries[0x40];
    void FUN_000df7b0(int a, int b);
};
void Table_df7b0::FUN_000df7b0(int a, int b) {
    int i = 0;
    while (i < 0x40 && entries[i].key != 0)
        i++;
    if (i < 0x40) {
        entries[i].key = FUN_000f6610(a);
        entries[i].value = b;
    }
}
