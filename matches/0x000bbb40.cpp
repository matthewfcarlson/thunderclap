extern "C" long __cdecl atol(const char*);
struct State_bbb40 {
    char pad[0x1cf8];
    long value;
};
class Handler_bbb40 {
  public:
    void* pad;
    State_bbb40* state;
    int FUN_000bbb40(int type, const char** value);
};
int Handler_bbb40::FUN_000bbb40(int type, const char** value) {
    if (state == 0)
        return -1;
    if (type != 1)
        return -1;
    state->value = atol(*value);
    return 0;
}
