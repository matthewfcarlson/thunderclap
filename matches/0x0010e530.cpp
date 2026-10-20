struct KeywordData {
    char pad[0x18];
    int first;
    int second;
};
struct Result {
    float FUN_00037290(int, int);
};
struct Stage {
    Result* FUN_00059a30();
};
struct Source {
    Stage* FUN_000592a0();
};
namespace hulkfight {
namespace ai {
struct KeywordWaitAction {
    char pad0[0x1c];
    KeywordData* data;
    Source* source;
    float value;
    int status;
    unsigned char vfunc_3(int unused1, int unused2);
};
unsigned char KeywordWaitAction::vfunc_3(int unused1, int unused2) {
    if (!source)
        return 0;
    Stage* stage = source->FUN_000592a0();
    Result* result = stage->FUN_00059a30();
    status = 0;
    int first = data->first;
    int second = data->second;
    value = result->FUN_00037290(first, second);
    return 1;
}
} // namespace ai
} // namespace hulkfight