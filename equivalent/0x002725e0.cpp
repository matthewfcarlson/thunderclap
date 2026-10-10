// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/12, incomplete)
// FUN_002725e0 @ 0x002725e0
extern "C" void __stdcall OutputDebugStringA(const char*);
void __cdecl FUN_002725e0(const char* text)
{
    if (!text) text = "NULL";
    unsigned int length = 0;
    while (text[length]) ++length;
    char buffer[257];
    unsigned int blocks = length >> 8;
    unsigned int remainder = length & 255;
    for (unsigned int i = 0; i < blocks; ++i) {
        for (unsigned int j = 0; j < 256; ++j) buffer[j] = text[i * 256 + j];
        buffer[256] = 0;
        OutputDebugStringA(buffer);
    }
    if (remainder) {
        for (unsigned int j = 0; j < remainder; ++j) buffer[j] = text[blocks * 256 + j];
        buffer[remainder] = 0;
        OutputDebugStringA(buffer);
    }
}