// STATUS: equivalent (tools/equiv.py level 3: 155 inputs, branch coverage 13/16, incomplete)
// FUN_002629a0 @ 0x002629a0
int __cdecl FUN_002628a0(int nibble, int *first, int *second);
struct State_2629a0 { short first; short second; };
struct DecodeScratch { int first; int second; const unsigned char *end; unsigned int channels; };
void __cdecl FUN_002629a0(short *output, const unsigned char *input, unsigned int blocks, unsigned int channels)
{
    State_2629a0 states[16];
    unsigned int blockBytes = channels * 20;
    DecodeScratch scratch;
    scratch.end = input + blockBytes * blocks;
    scratch.channels = channels;
    while (input < scratch.end) {
        const unsigned char *blockEnd = input + blockBytes;
        for (unsigned int c = 0; c < channels; ++c) {
            states[c].first = *(const short *)input; input += 2;
            states[c].second = *(const short *)input; input += 2;
        }
        while (input < blockEnd) {
            for (unsigned int c = 0; c < channels; ++c) {
                unsigned char packed = *input++;
                scratch.first = states[c].first;
                scratch.second = states[c].second;
                *output = (short)FUN_002628a0(packed & 15, &scratch.first, &scratch.second);
                output[scratch.channels] = (short)FUN_002628a0((packed >> 4) & 15, &scratch.first, &scratch.second);
                ++output;
                states[c].first = (short)scratch.first;
                states[c].second = (short)scratch.second;
            }
            output += channels;
        }
    }
}
