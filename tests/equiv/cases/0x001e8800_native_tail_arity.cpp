// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001e8800 @ 0x001e8800
struct Data { char pad[0x38]; void *buffer; unsigned int count; };
extern "C" int __cdecl FUN_00266eb0(int, void *, unsigned int);
extern "C" int __cdecl FUN_00266e00(int, void *);
extern "C" int __cdecl FUN_001e8800(int unused, Data *data) {
    if (data->count > 4)
        return FUN_00266eb0(6, data->buffer, data->count);
    return FUN_00266e00(6, data->buffer);
}