// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_00216e70 @ 0x00216e70
struct Data { char pad0[4]; unsigned int count; int capacity; char pad1[0x30]; void* buffer; char pad2[4]; unsigned int bufferSize; };
struct Owner { char pad[0x10]; Data* data; };
void __cdecl FUN_002192e0(Owner*, int);
void* __cdecl FUN_0021add0(Owner*, void*, unsigned int, unsigned int);
// equiv-conv: FUN_00216e70 ebx
void FUN_00216e70(Owner* owner) {
    Data* data = owner->data;
    int capacity = data->capacity;
    if (data->count < (unsigned int)((capacity + ((capacity >> 31) & 3)) >> 2) && data->capacity > 0x4000) {
        int value = data->capacity;
        FUN_002192e0(owner, (value - (value >> 31)) >> 1);
    }
    unsigned int size = data->bufferSize;
    if (size > 0x40) {
        unsigned int half = size >> 1;
        void* buffer = FUN_0021add0(owner, data->buffer, size, half);
        data->bufferSize = half;
        data->buffer = buffer;
    }
}