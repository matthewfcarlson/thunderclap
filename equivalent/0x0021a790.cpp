// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 3/3)
// FUN_0021a790 @ 0x0021a790
struct Record { char pad[12]; unsigned int length; char data[1]; };
struct Writer { void *context; void (__cdecl *write)(void *, const void *, unsigned int, void *); void *user; };
// equiv-conv: FUN_0021a790 eax esi
extern "C" void FUN_0021a790(void * record_, void *writer)
{
    Record * record = (Record *)record_;
    unsigned int header = 0;
    if (record && &record->data[0]) {
        const unsigned int payloadLength = record->length + 1;
        header = payloadLength;
        ((Writer *)writer)->write(((Writer *)writer)->context, &header, 4, ((Writer *)writer)->user);
        ((Writer *)writer)->write(((Writer *)writer)->context, record->data, payloadLength, ((Writer *)writer)->user);
    } else {
        unsigned int * volatile address = &header;
        ((Writer *)writer)->write(((Writer *)writer)->context, address, 4, ((Writer *)writer)->user);
    }
}