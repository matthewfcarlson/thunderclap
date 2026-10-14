// STATUS: equivalent (tools/equiv.py level 3: 244 inputs, branch coverage 11/12, incomplete)
// FUN_00304a10 @ 0x00304a10
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
void* __cdecl FUN_0008d6d0(int size);
void __cdecl thunk_FUN_00267090(void *p);

struct Pair {
    int a;
    int b;
};

class PairArray {
public:
    int count;
    int capacity;
    Pair *data;
    char pad0c;
    char deep;
    void Reserve(int wanted);
};

void PairArray::Reserve(int wanted)
{
    if (wanted == 0)
        wanted = 2;
    if (capacity >= wanted)
        return;
    Pair *fresh = (Pair *)FUN_0008d6d0(wanted * 8);
    if (count > 0) {
        if (deep) {
            for (int i = 0; i < count; i++) {
                fresh[i].a = data[i].a;
                fresh[i].b = data[i].b;
            }
        } else {
            memcpy(fresh, data, count * 8);
        }
    }
    thunk_FUN_00267090(data);
    data = fresh;
    capacity = wanted;
}
