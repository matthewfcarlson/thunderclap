struct Data {
    char pad[6];
    unsigned char flag;
    unsigned char count;
};
void __cdecl FUN_0021add0(void*, Data*, unsigned int, int);
extern "C" void __cdecl FUN_002197d0(void* context, void * data) {
    FUN_0021add0(context, ((Data *)data),
                 ((Data *)data)->flag ? (unsigned int)((Data *)data)->count * 8 + 0x10 : (unsigned int)((Data *)data)->count * 4 + 0x18, 0);
}