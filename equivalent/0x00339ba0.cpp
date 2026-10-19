// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00339ba0 @ 0x00339ba0
struct CallbackData { int first; int second; };
void FUN_00339a40();
int __cdecl FUN_00213b20(int, void (__cdecl *)(), CallbackData *, int);
int __cdecl FUN_002139f0(int, int, int, int);
// equiv-conv: FUN_00339ad0 eax esi
void FUN_00339ad0(int, int);
int __cdecl FUN_00339ba0(int source, int first, int second, int last)
{
    CallbackData data;
    data.first = first;
    data.second = second;
    int result = FUN_00213b20(source, FUN_00339a40, &data, last);
    if (result == 0)
        result = FUN_002139f0(source, 0, -1, 0);
    FUN_00339ad0(result, source);
    return result;
}