#include "compat/ptr.h"
extern "C" long __cdecl atol(const char*);
class Reader {
  public:
    char* GetText();
    void Advance();
};
extern "C" char __stdcall FUN_00336280(long* output, Reader* reader, void* unused, char indirect) {
    char* text = reader->GetText();
    if (!text)
        return 0;
    long* destination;
    if (indirect)
        destination = output;
    else
        destination = (long*)*(hulk_intptr*)output;
    *destination = atol(text);
    reader->Advance();
    text = reader->GetText();
    if (!text)
        return 0;
    destination[1] = atol(text);
    return 1;
}