// STATUS: equivalent (tools/equiv.py level 3: 8440 inputs, branch coverage 4/4)
// FUN_00220b20 @ 0x00220b20
// FUN_00220b20 @ 0x00220b20
struct Storage_220b20 {
 char pad0[12];
 unsigned int* first;
 char pad10[4];
 unsigned int* second;
 char pad18[20];
 int firstCapacity;
 int secondCapacity;
};
struct Context {
 Storage_220b20* storage;
 char pad4[12];
 void* allocator;
 char pad14[4];
 int count;
 char pad1c[4];
 int marker;
};
// equiv-conv: FUN_00220650 edx ebx stack stack stack stack stack
extern "C" void __cdecl FUN_00220650(int, void *, int, int, int, int, int);
void* __cdecl FUN_0021ae40(void* allocator, void* oldBuffer, int* capacity, int elementSize, int limit, const char* error);
extern "C" int __cdecl FUN_00220b20(void * context, unsigned int firstValue, unsigned int secondValue) {
 Storage_220b20* storage = ((Context *)context)->storage;
 int count = ((Context *)context)->count;
 FUN_00220650(((Context *)context)->marker, (Context *)((Context *)context), count, 255, count, 255, count);
 ((Context *)context)->marker = -1;
 if (((Context *)context)->count + 1 > storage->firstCapacity)
  storage->first = (unsigned int*)FUN_0021ae40(((Context *)context)->allocator, storage->first, &storage->firstCapacity, 4, 0x7ffffffd, "code size overflow");
 storage->first[((Context *)context)->count] = firstValue;
 if (((Context *)context)->count + 1 > storage->secondCapacity)
  storage->second = (unsigned int*)FUN_0021ae40(((Context *)context)->allocator, storage->second, &storage->secondCapacity, 4, 0x7ffffffd, "code size overflow");
 storage->second[((Context *)context)->count] = secondValue;
 int result = ((Context *)context)->count;
 ((Context *)context)->count = result + 1;
 return result;
}
