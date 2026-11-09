// ScriptHandler's watch list (include/decls/data/script.h ScriptWatchList): empty, every name "0", every value 0.
#include "decls/data/script.h"
class Table : public ScriptWatchList {
  public:
    Table();
};
Table::Table() {
    count = 0;
    for (int i = 0; i < 256; i++) {
        names[i][0] = '0';
        *(int*)&values[i] = 0;
    }
}
