extern const char fmt[];
extern const char ending[];
extern "C" char __cdecl output(const char*, const char*, ...);
class Handler {
  public:
    char check(char**);
};
char work(char** text, const char* value, Handler* handler) {
    char* s = *text;
    if (output(s, fmt, value) && handler->check(text)) {
        s = *text;
        return output(s, ending);
    }
    return 0;
}
