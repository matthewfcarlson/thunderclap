typedef unsigned int uint;
typedef unsigned char uchar;
extern "C" bool __cdecl Check(void*, uint);
bool __cdecl Target(void* p, int offset) {
    for (uint i = 0; i < 0x10; ++i) {
        if (!Check(p, i + offset))
            return false;
    }
    return true;
}