#include "decls/data/engine/audio.h"
#include "decls/data/game/global.h"

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
    if (Scan(text, DAT_004298a8, w) && checker->Check(node)) {
        const char* again = node->text;
        return Scan(again, DAT_00422518);
    }
    return 0;
}
