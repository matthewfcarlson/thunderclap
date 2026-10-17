struct Data {
    char pad[6];
    unsigned char flag;
    unsigned char count;
};
void __cdecl FUN_0021add0(void*, Data*, unsigned int, int);
void __cdecl FUN_002197d0(void* context, Data* data) {
    FUN_0021add0(context, data,
                 data->flag ? (unsigned int)data->count * 8 + 0x10 : (unsigned int)data->count * 4 + 0x18, 0);
}