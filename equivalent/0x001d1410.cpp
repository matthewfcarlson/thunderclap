// STATUS: equivalent (tools/equiv.py level 3: 2523 inputs, branch coverage 18/20, incomplete)
// FUN_001d1410 @ 0x001d1410
// 0x001d1410: insert an entry into a sorted pointer table of at most 20 entries
int __cdecl FUN_00096600(const char* a, const char* b);

struct Entry_1d1410 {
    int field_00;
    char name[1];
};

class SortedTable {
public:
    Entry_1d1410* items[20];
    int count;
    bool Insert(Entry_1d1410* e);
};

bool SortedTable::Insert(Entry_1d1410* e)
{
    if (count >= 20)
        return false;

    const char* name = e->name;
    int pos = 0;
    bool found = false;
    if (name != 0 && *name != 0) {
        for (int i = 0; i < count; i++) {
            const char* other = items[i]->name;
            if (other == 0 || *other == 0 || FUN_00096600(other, name) >= 0) {
                pos = i;
                found = true;
                break;
            }
        }
    }
    if (!found)
        pos = count;

    for (int i = count; i > pos; i--)
        items[i] = items[i - 1];
    items[pos] = e;
    count = count + 1;
    return true;
}
