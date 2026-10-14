// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 15/16, incomplete)
// FUN_0025c320 @ 0x0025c320
struct Header_25c320 { unsigned int flags; };
struct Row_25c320 { unsigned int values[4]; };
void __cdecl FUN_0025c320(Header_25c320* header, Row_25c320* output, unsigned char special, unsigned char extra)
{
    unsigned int count = (header->flags >> 4) & 31;
    if (count == 1) {
        unsigned int n;
        if (special) { output[0].values[0] = 8; n = 1; }
        else { output[0].values[0] = 1; output[0].values[1] = 2; n = 2; }
        if (extra) output[0].values[n++] = 7;
        while (n < 4) output[0].values[n++] = 0;
    } else {
        unsigned int i = 0;
        while (i < ((header->flags >> 4) & 31)) {
            output[i].values[0] = special ? 8 : ((i + 1) % 6);
            unsigned int n = 1;
            if (extra) output[i].values[n++] = 7;
            while (n < 4) output[i].values[n++] = 0;
            ++i;
        }
    }
}
