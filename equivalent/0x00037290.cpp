// STATUS: equivalent (tools/equiv.py level 3: 2412 inputs, branch coverage 8/8)
// FUN_00037290 @ 0x00037290
extern const float DAT_003f3388;
struct Object {
    char pad[0x1ba8];
    struct Entry { int first; int second; float value; int unused; } entries[14];
    int count;
    float FUN_00037290(int first, int second);
};
float Object::FUN_00037290(int first, int second) {
    int n = count;
    for (int i = 0; i < n; ++i) {
        if (entries[i].first == first && entries[i].second == second)
            return entries[i].value;
    }
    return DAT_003f3388;
}