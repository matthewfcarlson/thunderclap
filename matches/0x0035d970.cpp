struct Pair {
    int a;
    int b;
};

extern "C" Pair FindRow(const char*);
extern "C" Pair g_row;

void FUN_0035d970() {
    g_row = FindRow("RowBackgrounds");
}
