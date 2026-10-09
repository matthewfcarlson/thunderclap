extern "C" long __cdecl atol(const char *);
struct State { char pad[0x1cf8]; long value; };
class Handler { public: void * pad; State * state; int FUN_000bbb40(int type, const char ** value); };
int Handler::FUN_000bbb40(int type, const char ** value)
{
    if (state == 0) return -1;
    if (type != 1) return -1;
    state->value = atol(*value);
    return 0;
}
