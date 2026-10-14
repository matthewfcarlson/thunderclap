// STATUS: equivalent (tools/equiv.py level 3: 2599 inputs, branch coverage 4/4)
// FUN_00220b20 @ 0x00220b20
struct Storage {
 char pad0[12];
 unsigned int* first;
 char pad10[4];
 unsigned int* second;
 char pad18[20];
 int firstCapacity;
 int secondCapacity;
};
struct Context {
 Storage* storage;
 char pad4[12];
 void* allocator;
 char pad14[4];
 int count;
 char pad1c[4];
 int marker;
};
// equiv-conv: FUN_00220650 edx stack stack stack stack stack
void FUN_00220650(int marker, int a, int b, int c, int d, int e);
void* __cdecl FUN_0021ae40(void* allocator, void* oldBuffer, int* capacity, int elementSize, int limit, const char* error);
int __cdecl FUN_00220b20(Context* context, unsigned int firstValue, unsigned int secondValue) {
 Storage* storage = context->storage;
 int count = context->count;
 FUN_00220650(context->marker, count, 255, count, 255, count);
 context->marker = -1;
 if (context->count + 1 > storage->firstCapacity)
  storage->first = (unsigned int*)FUN_0021ae40(context->allocator, storage->first, &storage->firstCapacity, 4, 0x7ffffffd, "code size overflow");
 storage->first[context->count] = firstValue;
 if (context->count + 1 > storage->secondCapacity)
  storage->second = (unsigned int*)FUN_0021ae40(context->allocator, storage->second, &storage->secondCapacity, 4, 0x7ffffffd, "code size overflow");
 storage->second[context->count] = secondValue;
 int result = context->count;
 context->count = result + 1;
 return result;
}
