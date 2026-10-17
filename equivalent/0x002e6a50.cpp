// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_002e6a50 @ 0x002e6a50
extern "C" void* __cdecl malloc(unsigned int);
typedef void* (__cdecl *Allocator)(int, unsigned int);
void* __cdecl FUN_002e6a50(int type, Allocator allocator)
{
    unsigned int size;
    if (type == 2) size = 0xb8;
    else if (type == 1) size = 0x21c;
    else return 0;
    void* result = allocator ? allocator(0, size) : malloc(size);
    if (result) {
        unsigned char* bytes = (unsigned char*)result;
        for (unsigned int i = 0; i < size; ++i) bytes[i] = 0;
    }
    return result;
}