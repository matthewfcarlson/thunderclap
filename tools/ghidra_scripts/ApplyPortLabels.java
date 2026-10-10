// Apply the platform-boundary / QoL names written by tools/platform_map.py (build/port/labels.json).
//
// Function names are left alone on purpose: tools/packet.py treats a function as game code by its
// FUN_/vfunc_ name, so renaming would change the farm queue after the next ExportFunctions. In
// Ghidra a label at a function entry with a default (FUN_) name becomes the function's name, so
// functions get a plate comment "[port] <name>" instead. Data addresses get a label.
//
// Re-runnable. It also repairs the first version of this script, which created labels at function
// entries: such a label is removed and a FUN_ name it displaced is restored.
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
import ghidra.program.model.listing.CodeUnit;
import ghidra.program.model.listing.Function;
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
        int labels = 0, comments = 0, restored = 0, removed = 0;
        while (m.find()) {
            Address a = toAddr(Long.decode(m.group(1)));
            String name = m.group(2).replace("::", "__");
            Function f = getFunctionAt(a);
            if (f != null) {
                if (f.getName().equals(name)) {
                    String def = String.format("FUN_%08x", a.getOffset());
                    try {
                        f.setName(def, SourceType.DEFAULT);
                    } catch (Exception e) {
                        f.setName(def, SourceType.ANALYSIS);
                    }
                    restored++;
                }
                for (Symbol s : st.getSymbols(a)) {
                    if (s.getName().equals(name) && !s.isPrimary()) {
                        s.delete();
                        removed++;
                    }
                }
                String note = "[port] " + m.group(2);
                CodeUnit cu = currentProgram.getListing().getCodeUnitAt(a);
                String plate = cu == null ? null : cu.getComment(CodeUnit.PLATE_COMMENT);
                if (cu != null && (plate == null || !plate.contains(note))) {
                    cu.setComment(CodeUnit.PLATE_COMMENT, plate == null ? note : plate + "\n" + note);
                    comments++;
                }
                continue;
            }
            boolean exists = false;
            for (Symbol s : st.getSymbols(a)) {
                if (s.getName().equals(name)) exists = true;
            }
            if (!exists) {
                st.createLabel(a, name, SourceType.USER_DEFINED);
                labels++;
            }
        }
        println("ApplyPortLabels: " + labels + " data labels, " + comments + " function comments, "
            + restored + " function names restored, " + removed + " stray labels removed");
    }
}
