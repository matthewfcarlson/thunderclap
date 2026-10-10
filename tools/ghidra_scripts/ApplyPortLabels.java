// Apply the platform-boundary / QoL labels written by tools/platform_map.py (build/port/labels.json).
// Re-runnable and additive: every name becomes a secondary (non-primary) label, so function names
// stay FUN_xxx / Class::vfunc_N. That matters: tools/packet.py treats a function as game code by its
// FUN_/vfunc_ name, so renaming would drop it from the farm after the next ExportFunctions. Labels
// that already exist are skipped; nothing is deleted.
//
// Run (needs the project opened for writing, so no other Ghidra process may be running):
//   analyzeHeadless build/ghidra hulk -process default.xbe -noanalysis \
//     -scriptPath tools/ghidra_scripts -postScript ApplyPortLabels.java build/port/labels.json
//@category Hulk

import java.nio.file.Files;
import java.nio.file.Path;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolTable;

public class ApplyPortLabels extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String path = getScriptArgs().length > 0 ? getScriptArgs()[0] : "build/port/labels.json";
        String json = Files.readString(Path.of(path));
        // The file is a flat {"0xADDR": "name", ...} object; no JSON library needed.
        Matcher m = Pattern.compile("\"(0x[0-9a-fA-F]+)\"\\s*:\\s*\"([^\"]+)\"").matcher(json);
        SymbolTable st = currentProgram.getSymbolTable();
        int labelled = 0, present = 0;
        while (m.find()) {
            Address a = toAddr(Long.decode(m.group(1)));
            String name = m.group(2).replace("::", "__");
            boolean exists = false;
            for (Symbol s : st.getSymbols(a)) {
                if (s.getName().equals(name)) exists = true;
            }
            if (exists) {
                present++;
                continue;
            }
            Symbol s = st.createLabel(a, name, SourceType.USER_DEFINED);
            if (s.isPrimary() && getFunctionAt(a) != null) {
                // keep the function's own name primary
                getFunctionAt(a).getSymbol().setPrimary();
            }
            labelled++;
        }
        println("ApplyPortLabels: added " + labelled + " labels, " + present + " already present");
    }
}
