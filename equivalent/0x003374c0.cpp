// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// FUN_003374c0 @ 0x003374c0
extern char DAT_0055dbc0[1024];
extern "C" int __cdecl sprintf(char *, const char *, ...);
struct Token { const char * FUN_00338a10(); };
struct Parser {
 char pad[0x5108];
 unsigned error;
 Token *token;
 const char * FUN_003374c0();
};
const char * Parser::FUN_003374c0() {
 DAT_0055dbc0[0] = 0;
 const char *name = token ? token->FUN_00338a10() : 0;
 if (!name) name = "<?>";
 switch(error) {
 case 0: return "No error.";
 case 1: return "Hit EOF, no error.";
 case 2: return "Ending quotation \" expected.";
 case 3: return "Token size is too big. Did you forget a quotation?";
 case 4: sprintf(DAT_0055dbc0, "Syntax error, bad command '%s'.", name); return DAT_0055dbc0;
 case 5: return "Too many object definitions. Increase MAX_OBJECT_DEFINITIONS in datadefinition.h";
 case 6: return "Too many attribute definitions for a single object. Increase MAX_ATTRIBUTE_DEFIN";
 case 7: sprintf(DAT_0055dbc0, "Duplicate object name '%s'.", name); return DAT_0055dbc0;
 case 8: sprintf(DAT_0055dbc0, "Duplicate attribute name '%s'.", name); return DAT_0055dbc0;
 case 9: return "File was not found";
 case 10: sprintf(DAT_0055dbc0, "Unknown data type '%s'.", name); return "Nesting of array data definitions is not supported at this time.";
 case 11: return "Nesting of array data definitions is not supported at this time.";
 default: return "Unknown Error...something is really wrong";
 }
}
