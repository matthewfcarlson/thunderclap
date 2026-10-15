extern const char gFmt[];
extern const char gEnd[];
extern "C" char __cdecl Scan(const char*, const char*, ...);
struct Node {
    const char* text;
};
class Checker {
  public:
    char Check(Node*);
};
char __cdecl target(Node* node, char* word, Checker* checker) {
    char* w = word;
    const char* text = node->text;
    if (Scan(text, gFmt, w) && checker->Check(node)) {
        const char* again = node->text;
        return Scan(again, gEnd);
    }
    return 0;
}
