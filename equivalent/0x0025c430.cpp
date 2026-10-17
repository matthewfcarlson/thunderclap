// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/7)
// FUN_0025c430 @ 0x0025c430
extern "C" int __cdecl FUN_00246f50(void *, const char *, const char *);
unsigned char __cdecl FUN_0025c430(void **destination, unsigned int encoding)
{
    const char *name;
    switch (encoding) {
    case 0: name = "HalEncodingType_Pcm"; break;
    case 1: name = "HalEncodingType_Vag"; break;
    case 2: name = "HalEncodingType_PcmBigEndian"; break;
    case 3: name = "HalEncodingType_XBoxAdpcm"; break;
    case 4: name = "HalEncodingType_RadicalAdpcm"; break;
    default: return 0;
    }
    return (unsigned char)FUN_00246f50(*destination, "%s", name);
}
