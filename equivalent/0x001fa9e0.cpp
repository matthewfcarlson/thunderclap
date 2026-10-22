// STATUS: equivalent (tools/equiv.py level 3: 2462 inputs, branch coverage 4/4)
// MyBufferStream::vfunc_3 @ 0x001fa9e0
typedef unsigned char byte;
extern "C" void * __cdecl memcpy(void *, const void *, unsigned int);
struct Stream_1fa9e0 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(void *, unsigned int); virtual void vfunc_4(); };
struct MyBufferStream : Stream_1fa9e0 { byte *data; int length; int position; virtual void vfunc_3(void *destination, unsigned int count); };
void MyBufferStream::vfunc_3(void *destination, unsigned int count) {
    int available = length - position;
    if ((int)(position + count) > length) count = available;
    if ((int)count > 0) {
        memcpy(destination, data + position, count);
        position += count;
    }
}