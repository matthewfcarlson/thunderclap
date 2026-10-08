// Print basic analysis stats: functions, named functions, vftables/RTTI symbols.
// Run: analyzeHeadless build/ghidra hulk -process default.xbe -noanalysis -readOnly \
//        -scriptPath tools/ghidra_scripts -postScript ProjectStats.java
//@category Hulk

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;

public class ProjectStats extends GhidraScript {
    @Override
    protected void run() throws Exception {
        int total = 0, named = 0, thunks = 0;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            total++;
            if (f.isThunk()) thunks++;
            if (!f.getName().startsWith("FUN_")) named++;
        }
        int vftables = 0, rtti = 0;
        SymbolIterator it = currentProgram.getSymbolTable().getAllSymbols(true);
        while (it.hasNext()) {
            Symbol s = it.next();
            String n = s.getName();
            if (n.contains("vftable")) vftables++;
            if (n.startsWith("RTTI_")) rtti++;
        }
        println(String.format("functions=%d named=%d thunks=%d vftables=%d rtti_symbols=%d",
                total, named, thunks, vftables, rtti));
    }
}
