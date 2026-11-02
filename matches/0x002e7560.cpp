typedef unsigned char byte;
extern "C" unsigned short __cdecl FUN_002e7560(const unsigned char * data) {
    register unsigned short a = (unsigned short)data[0];
    register unsigned short b = (unsigned short)data[1];
    a <<= 8;
    a += b;
    return a;
}