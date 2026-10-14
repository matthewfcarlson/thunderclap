// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000c93e0 @ 0x000c93e0
// equiv-map: ??1Key@@QAE@XZ = 0x0027af50
struct Triple {
    int a, b, c;
};

struct Key {
    int a, b, c;
    ~Key() throw();
    int FUN_0027b0e0(int index) throw();
};

class Host {
public:
    int FUN_000c8200(int a1, int handle, Triple t1, Triple t2, Key key) throw();
    int FUN_000c93e0(int a1, int index, Triple t1, Triple t2, Key key) throw();
};

int Host::FUN_000c93e0(int a1, int index, Triple t1, Triple t2, Key key) throw() {
    return FUN_000c8200(a1, key.FUN_0027b0e0(index), t1, t2, key);
}
