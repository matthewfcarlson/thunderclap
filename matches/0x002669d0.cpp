extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
class Copy {
  public:
    void CopyText(const char* source);
};
void Copy::CopyText(const char* source) {
    strncpy((char*)this, source, 0x7f);
}