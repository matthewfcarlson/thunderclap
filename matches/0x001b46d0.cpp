#include "decls/data/game/global.h"

class OtherClass {
  public:
    void Other(int a, float b, float c);
};
class Target {
  public:
    char pad[0x5a8];
    float value;
    void Fn(int a, float b, float c);
};
void Target::Fn(int a, float b, float c) {
    value = b;
    (*(OtherClass**)&DAT_00554c10)->Other(a, b, c);
}