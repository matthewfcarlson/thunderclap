// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 20/20)
// FUN_001d1180 @ 0x001d1180
struct Entry {
    char pad0[8];
    const char *name;
};

int __cdecl FUN_00096600(const char *a, const char *b);

class SortedList {
public:
    Entry *items[0x400];
    int count;      // 0x1000
    bool FUN_001d1180(Entry *e);
};

bool SortedList::FUN_001d1180(Entry *e)
{
    const char *name = e->name;
    if (count >= 0x400)
        return false;
    int pos = -1;
    if (name != 0 && *name != 0) {
        for (int i = 0; i < count; i++) {
            const char *other = items[i]->name;
            if (other == 0 || *other == 0 || FUN_00096600(other, name) >= 0) {
                pos = i;
                break;
            }
        }
    }
    if (pos < 0)
        pos = count;
    for (int j = count; j > pos; j--)
        items[j] = items[j - 1];
    items[pos] = e;
    count++;
    return true;
}
