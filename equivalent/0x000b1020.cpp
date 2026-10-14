// STATUS: equivalent (tools/equiv.py level 3: 1429 inputs, branch coverage 11/12, incomplete)
// FUN_000b1020 @ 0x000b1020
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d330
void __cdecl thunk_FUN_00267090(void *p);
void *__cdecl FUN_0008d750(int size, int align);
int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);

class StringTable_b1020 {
public:
    int count;
    char (*data)[32];
    void FUN_000b1020(int n);
};

void StringTable_b1020::FUN_000b1020(int n)
{
    if (count == n)
        return;
    if (data != 0) {
        thunk_FUN_00267090(data);
        count = 0;
        data = 0;
    }
    count = n;
    data = (char (*)[32])FUN_0008d750(n << 5, 4);
    for (int i = 0; i < count; i++)
        FUN_00267760(data[i], 0x20, "");
}
