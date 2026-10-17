// STATUS: equivalent (tools/equiv.py level 3: 1548 inputs, branch coverage 10/10)
// FUN_00065dd0 @ 0x00065dd0
struct Pair { int first; int second; };
struct List {
    char reserved[0x10];
    Pair entries[40];
    int count;
    void FUN_00065dd0(const Pair* item);
};
void List::FUN_00065dd0(const Pair* item) {
    int originalCount = count;
    for (int i = 0; i < originalCount; ++i) {
        if (entries[i].first == item->first && entries[i].second == item->second)
            return;
        if (i + 1 >= count)
            break;
    }
    if (originalCount < 40) {
        entries[originalCount].first = item->first;
        entries[originalCount].second = item->second;
        ++count;
    }
}