// STATUS: equivalent (tools/equiv.py level 3: 20008 inputs, branch coverage 6/6)
// FUN_00339c30 @ 0x00339c30
// cl-flags: /GS
struct DebugInfo_339c30 {
    int event;
    const char* name;
    const char* namewhat;
    char rest[84];
};
struct State;
extern "C" int __cdecl FUN_00213fc0(State*, int, DebugInfo_339c30*);
extern "C" int __cdecl FUN_00214bd0(State*, const char*, DebugInfo_339c30*);
extern "C" int __cdecl FUN_00338e20(State*, const char*, ...);
int __cdecl FUN_00339c30(State* state, int argument, const char* message) {
    DebugInfo_339c30 info;
    FUN_00213fc0(state, 0, &info);
    FUN_00214bd0(state, "n", &info);
    const char* kind = info.namewhat;
    const char* method = "method";
    int i;
    for (i = 0; i < 7; ++i) {
        if (kind[i] != method[i]) break;
    }
    int result;
    if (i == 7 && --argument == 0) {
        result = FUN_00338e20(state, "calling `%s' on bad self (%s)", info.name, message);
    } else {
        if (!info.name) info.name = "?";
        result = FUN_00338e20(state, "bad argument #%d to `%s' (%s)", argument, info.name, message);
    }
    return result;
}
