// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 9/10, incomplete)
// FUN_00025820 @ 0x00025820
extern int DAT_003fa114;
extern const char* DAT_0049548c[];
extern int __cdecl FUN_00096600(const char*, const char*);
extern void* __cdecl FUN_00267830(void* dst, const void* src, int n);
class Table {
  public:
    char pad[0xc10];
    char names[9][32];
    void FUN_00025820(const char* name, const void* src);
};
void Table::FUN_00025820(const char* name, const void* src) {
    int i = 0;
    if (DAT_003fa114 > 0) {
        do {
            if (FUN_00096600(name, DAT_0049548c[i]) == 0) {
                int k = i - 1;
                if (k >= 0 && k < 9)
                    FUN_00267830(names[k], src, 0x20);
                return;
            }
            i++;
        } while (i < DAT_003fa114);
    }
}
