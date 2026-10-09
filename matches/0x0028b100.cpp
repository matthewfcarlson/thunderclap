class C { public: void Decode(int, int*); };
extern "C" int __cdecl Target(C* a, C* b, float scale, int input)
{
    int x;
    int y;
    a->Decode(input, &x);
    b->Decode(input, &y);
    int d = y - x;
    return (int)((float)d * scale) + x;
}
