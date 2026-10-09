struct Owner { char pad[8]; int value; bool Target(float*); };
int __cdecl ReadState(int, int);
float __cdecl ReadAmount(int, int);
void __cdecl FinishState(int, int);
bool Owner::Target(float* out)
{
    bool result = true;
    int state = ReadState(value, -1);
    if (state != 3) result = false;
    else *out = ReadAmount(value, -1);
    FinishState(value, -2);
    return result;
}