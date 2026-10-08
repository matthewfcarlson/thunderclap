// Apply build/rtti.json (from tools/rtti.py): class namespaces, RTTI/vftable labels,
// vtable pointer arrays, and Class::vfunc_N names for virtual functions.
// Only renames functions that still have default (FUN_) names.
//
// Run: analyzeHeadless build/ghidra hulk -process default.xbe -noanalysis \
//        -scriptPath tools/ghidra_scripts -postScript ApplyRtti.java build/rtti.json
//@category Hulk

import java.io.FileReader;
import java.util.*;

import com.google.gson.*;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.util.CodeUnitInsertionException;
import ghidra.program.model.data.DataUtilities.ClearDataMode;
import ghidra.app.util.NamespaceUtils;

public class ApplyRtti extends GhidraScript {

    private SymbolTable st;
    private int created, renamed, labeled;

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        String path = args.length > 0 ? args[0] : askFile("rtti.json", "Open").getAbsolutePath();
        JsonObject root = JsonParser.parseReader(new FileReader(path)).getAsJsonObject();
        JsonArray classes = root.getAsJsonArray("classes");
        st = currentProgram.getSymbolTable();

        // Pass 1: pick an owner for each virtual function = class with fewest bases using it.
        Map<Long, Owner> owners = new HashMap<>();
        Set<Long> ambiguous = new HashSet<>();
        for (JsonElement ce : classes) {
            JsonObject c = ce.getAsJsonObject();
            if (c.get("name").isJsonNull()) continue;
            int nbases = c.getAsJsonArray("bases").size();
            for (JsonElement ve : c.getAsJsonArray("vtables")) {
                JsonObject v = ve.getAsJsonObject();
                JsonArray slots = v.getAsJsonArray("slots");
                for (int i = 0; i < slots.size(); i++) {
                    long f = slots.get(i).getAsLong();
                    Owner cand = new Owner(c.get("name").getAsString(), nbases, i, v.get("offset").getAsInt());
                    Owner cur = owners.get(f);
                    if (cur == null || cand.nbases < cur.nbases) {
                        owners.put(f, cand);
                        ambiguous.remove(f);
                    } else if (cand.nbases == cur.nbases && (!cand.cls.equals(cur.cls) || cand.slot != cur.slot)) {
                        ambiguous.add(f);
                    }
                }
            }
        }

        // Pass 2: namespaces, labels, data.
        Map<String, Namespace> nsByName = new HashMap<>();
        monitor.initialize(classes.size());
        monitor.setMessage("Applying RTTI");
        for (JsonElement ce : classes) {
            monitor.checkCancelled();
            monitor.incrementProgress(1);
            JsonObject c = ce.getAsJsonObject();
            Namespace ns = c.get("name").isJsonNull() ? null : classNamespace(c.get("name").getAsString());
            if (ns != null) nsByName.put(c.get("name").getAsString(), ns);
            Namespace labelNs = ns != null ? ns : currentProgram.getGlobalNamespace();

            label(addr(c.get("td").getAsLong()), "RTTI_Type_Descriptor", labelNs);
            for (JsonElement ve : c.getAsJsonArray("vtables")) {
                JsonObject v = ve.getAsJsonObject();
                int off = v.get("offset").getAsInt();
                String suffix = off == 0 ? "" : String.format("_%x", off);
                Address vft = addr(v.get("address").getAsLong());
                label(addr(v.get("col").getAsLong()), "RTTI_Complete_Object_Locator" + suffix, labelNs);
                label(vft, "vftable" + suffix, labelNs);
                int n = v.getAsJsonArray("slots").size();
                if (n > 0) {
                    try {
                        DataUtilities.createData(currentProgram, vft,
                            new ArrayDataType(PointerDataType.dataType, n, 4), -1,
                            ClearDataMode.CLEAR_ALL_UNDEFINED_CONFLICT_DATA);
                    } catch (CodeUnitInsertionException e) {
                        // Leave existing defined data alone.
                    }
                }
            }
        }

        // Pass 3: functions.
        FunctionManager fm = currentProgram.getFunctionManager();
        monitor.initialize(owners.size());
        monitor.setMessage("Naming virtual functions");
        for (Map.Entry<Long, Owner> e : owners.entrySet()) {
            monitor.checkCancelled();
            monitor.incrementProgress(1);
            Address a = addr(e.getKey());
            Function f = fm.getFunctionAt(a);
            if (f == null) {
                disassemble(a);
                f = createFunction(a, null);
                if (f == null) continue;
                created++;
            }
            if (ambiguous.contains(e.getKey()) || f.getSymbol().getSource() != SourceType.DEFAULT) continue;
            Owner o = e.getValue();
            Namespace ns = nsByName.get(o.cls);
            if (ns == null) continue;
            String name = "vfunc_" + o.slot + (o.offset == 0 ? "" : String.format("_adj%x", o.offset));
            f.setParentNamespace(ns);
            f.setName(name, SourceType.ANALYSIS);
            if (o.offset == 0) f.setCallingConvention("__thiscall");
            renamed++;
        }
        println(String.format("ApplyRtti: labels=%d functions_created=%d functions_renamed=%d ambiguous=%d",
            labeled, created, renamed, ambiguous.size()));
    }

    private Address addr(long va) {
        return currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(va);
    }

    private void label(Address a, String name, Namespace ns) throws Exception {
        Symbol s = st.getSymbol(name, a, ns);
        if (s == null) {
            s = st.createLabel(a, name, ns, SourceType.ANALYSIS);
            labeled++;
        }
        s.setPrimary();
    }

    /** "a::B<c::D>::E" -> nested namespaces, last one a class. */
    private Namespace classNamespace(String qualified) throws Exception {
        List<String> parts = splitQualified(qualified);
        Namespace parent = currentProgram.getGlobalNamespace();
        for (int i = 0; i < parts.size(); i++) {
            String part = cleanName(parts.get(i));
            Namespace ns = st.getNamespace(part, parent);
            boolean last = i == parts.size() - 1;
            if (ns == null) {
                ns = last ? st.createClass(parent, part, SourceType.ANALYSIS)
                          : st.createNameSpace(parent, part, SourceType.ANALYSIS);
            } else if (last && !(ns instanceof GhidraClass)) {
                ns = NamespaceUtils.convertNamespaceToClass(ns);
            }
            parent = ns;
        }
        return parent;
    }

    private static List<String> splitQualified(String s) {
        List<String> out = new ArrayList<>();
        int depth = 0, start = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == '<') depth++;
            else if (ch == '>') depth--;
            else if (depth == 0 && ch == ':' && i + 1 < s.length() && s.charAt(i + 1) == ':') {
                out.add(s.substring(start, i));
                start = i + 2;
                i++;
            }
        }
        out.add(s.substring(start));
        return out;
    }

    private static String cleanName(String s) {
        s = s.replaceAll("\\b(class|struct|union|enum) ", "");
        return SymbolUtilities.replaceInvalidChars(s, true);
    }

    private static class Owner {
        final String cls;
        final int nbases, slot, offset;
        Owner(String cls, int nbases, int slot, int offset) {
            this.cls = cls; this.nbases = nbases; this.slot = slot; this.offset = offset;
        }
    }
}
