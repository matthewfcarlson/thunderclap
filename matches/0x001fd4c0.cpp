unsigned int __stdcall SetX(unsigned int x) {
    *(unsigned int*)0x4c83e8 = x;
    return x;
}