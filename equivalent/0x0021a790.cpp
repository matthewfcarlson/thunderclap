// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 3/3)
// FUN_0021a790 @ 0x0021a790
struct Record { char pad[12]; unsigned int length; char data[1]; };
struct Writer { void *context; void (__cdecl *write)(void *, const void *, unsigned int, void *); void *user; };
// equiv-conv: FUN_0021a790 eax esi
void FUN_0021a790(Record *record, Writer *writer)
{
    unsigned int header = 0;
    if (record && &record->data[0]) {
        const unsigned int payloadLength = record->length + 1;
        header = payloadLength;
        writer->write(writer->context, &header, 4, writer->user);
        writer->write(writer->context, record->data, payloadLength, writer->user);
    } else {
        unsigned int * volatile address = &header;
        writer->write(writer->context, address, 4, writer->user);
    }
}