struct Pair_35d970 {
    int a;
    int b;
};

extern "C" Pair_35d970 FindRow(const char*);
extern "C" Pair_35d970 g_row;

void FUN_0035d970() {
    g_row = FindRow("RowBackgrounds");
}
