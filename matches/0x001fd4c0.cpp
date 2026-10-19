extern "C" char hulk_at_004c83e8[];
unsigned int __stdcall SetX(unsigned int x) {
    *(unsigned int*)((int)hulk_at_004c83e8) = x;
    return x;
}