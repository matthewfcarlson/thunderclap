extern "C" long __cdecl atol(const char*);
class Reader {
  public:
    char* GetText();
    void Advance();
};
char __stdcall ParsePair(long* output, Reader* reader, void* unused, char indirect) {
    char* text = reader->GetText();
    if (!text)
        return 0;
    long* destination;
    if (indirect)
        destination = output;
    else
        destination = (long*)*output;
    *destination = atol(text);
    reader->Advance();
    text = reader->GetText();
    if (!text)
        return 0;
    destination[1] = atol(text);
    return 1;
}