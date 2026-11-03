typedef unsigned int uint;
extern int FUN_002142d0(void*, int, int);
extern "C" int FUN_002146a0(void* object) {
    return FUN_002142d0(object, *(int*)((char*)object + 0x2c), 0xff) != 0;
}