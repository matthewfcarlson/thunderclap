struct Entry {
    char pad[8];
    int type;
};
struct Table {
    char pad[0x44];
    int count;
    Entry* FUN_00337090(int index);
};
struct Pair {
    int first;
    int second;
};
struct Owner {
    char pad[4];
    Table* table;
    Pair** pairs;
    bool FUN_00335680(int index, int* first, int* second);
};
bool Owner::FUN_00335680(int index, int* first, int* second) {
    if (index < 0)
        return false;
    if (index >= table->count)
        return false;
    if (table->FUN_00337090(index)->type != 5)
        return false;
    Pair* pair = pairs[index];
    *first = pair->first;
    *second = pair->second;
    return true;
}