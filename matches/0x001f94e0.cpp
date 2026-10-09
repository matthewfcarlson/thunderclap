class CEncounterGenerator {
public:
    class Inner {
    public:
        void Close();
        int mValue;
    };
    class CEncounter {
    public:
        virtual ~CEncounter();
        char pad[0x2c];
        Inner mInner;
    };
};

CEncounterGenerator::CEncounter::~CEncounter() {
    mInner.Close();
}
