// STATUS: equivalent (tools/equiv.py level 3: 54 inputs, branch coverage 31/32, incomplete)
// FUN_0026c840 @ 0x0026c840
typedef unsigned int uint;
struct AllocState { unsigned char flags; char pad[0x453]; uint saved; };
struct Chunk { uint previousSize; uint size; };
extern AllocState *DAT_0052839c;
void __cdecl FUN_0026b970(AllocState *);
void * __cdecl FUN_0026c040(uint);
// equiv-conv: FUN_0026c840 eax stack stack stack
void ** __cdecl FUN_0026c840(void **result, uint count, const uint *sizes, uint flags)
{
    AllocState *state = DAT_0052839c;
    if (!(state->flags & 1)) FUN_0026b970(state);
    if (!count) {
        if (result) return result;
        return (void **)FUN_0026c040(0);
    }
    uint arraySize = 0;
    if (!result) {
        uint n = count * 4 + 11;
        arraySize = n < 16 ? 16 : n & ~7u;
    }
    uint uniform = 0, total = 0;
    if (flags & 1) {
        uint n = sizes[0] + 11;
        uniform = n < 16 ? 16 : n & ~7u;
        total = uniform * count;
    } else {
        for (uint i = 0; i != count; ++i) {
            uint n = sizes[i] + 11;
            total += n < 16 ? 16 : n & ~7u;
        }
    }
    uint saved = state->saved;
    state->saved = 0;
    char *memory = (char *)FUN_0026c040(arraySize + total - 7);
    DAT_0052839c->saved = saved;
    if (!memory) return 0;
    Chunk *block = (Chunk *)memory - 1;
    uint remaining = block->size & ~3u;
    if (flags & 2) {
        uint len = remaining - arraySize - 4;
        for (uint j = 0; j != len; ++j) memory[j] = 0;
    }
    if (!result) {
        Chunk *arrayChunk = (Chunk *)((char *)block + total);
        arrayChunk->size = (remaining - total) | 1;
        result = (void **)(arrayChunk + 1);
        remaining = total;
    }
    result[0] = block + 1;
    for (uint k = 1; k != count; ++k) {
        uint n = uniform;
        if (!n) {
            n = sizes[k-1] + 11;
            n = n < 16 ? 16 : n & ~7u;
        }
        block->size = n | 1;
        block = (Chunk *)((char *)block + n);
        remaining -= n;
        result[k] = block + 1;
    }
    block->size = remaining | 1;
    return result;
}