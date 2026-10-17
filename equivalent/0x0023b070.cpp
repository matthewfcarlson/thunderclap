// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// fight::ScriptReader::vfunc_5 @ 0x0023b070
namespace fight {
struct ScriptReader {
    char reserved[0x12c];
    int count;
    char gap[8];
    struct Entry { int kind; int value; float first; float second; char rest[8]; } entries[1];
    int FUN_0023ae90(int a, int b, int kind);
    bool vfunc_5(int a, int b, void* output);
};
bool ScriptReader::vfunc_5(int a, int b, void* output) {
    int index = FUN_0023ae90(a, b, 8);
    if (index < 0 || index >= count || entries[index].kind != 8)
        return false;
    struct Result { int value; float first; float second; };
    Result* result = (Result*)output;
    result->value = entries[index].value;
    result->first = entries[index].first;
    result->second = entries[index].second;
    return true;
}
}