// FUN_001d0730 @ 0x001d0730
// 0x001d0730: Lua C function: array[(int)arg] = number (arg 3), with a subscript error
struct lua_State;
float* __cdecl FUN_00213260(lua_State* L, int idx);
void __cdecl FUN_00339d70(lua_State* L, int a, int b);
void __cdecl FUN_002136d0(lua_State* L, int idx);
void __cdecl FUN_00212ed0(lua_State* L, int idx);
void __cdecl FUN_00213600(lua_State* L, int idx);
int __cdecl FUN_00212f70(lua_State* L, int idx);
float __cdecl FUN_002130e0(lua_State* L, int idx);
void __cdecl FUN_00213380(lua_State* L, const char* msg, int len);
void __cdecl FUN_00213c40(lua_State* L);

int FUN_001d0730(lua_State* L)
{
    float* array = FUN_00213260(L, 1);
    FUN_00339d70(L, 3, 3);
    FUN_002136d0(L, 1);
    FUN_00212ed0(L, 2);
    FUN_00213600(L, -2);
    if (FUN_00212f70(L, -1) != 0) {
        int index = (int)FUN_002130e0(L, -1);
        array[index] = FUN_002130e0(L, 3);
        return 0;
    }
    FUN_00213380(L, "invalid subscript in assignment", 0x1f);
    FUN_00213c40(L);
    return 0;
}
