// Durable matching farm: runs many cheap-model conversations in parallel, one per (function, tier),
// on pi-durable over SQLite. Each worker only has submit_cpp, which compiles and diffs a candidate.
//
// Usage (from repo root): farm/run.sh [--limit N] [--concurrency C] [--queue FILE] [--tiers FILE] [--only 0xADDR,...]

import { execFile } from "node:child_process";
import { appendFileSync, copyFileSync, existsSync, mkdirSync, readdirSync, readFileSync, writeFileSync } from "node:fs";
import { join } from "node:path";
import { promisify } from "node:util";
import { parseArgs } from "node:util";

import { Agent, setGlobalDispatcher } from "undici";

import { BACKGROUND_CONTEXT } from "@earendil-works/chord/context";
import { Type } from "@earendil-works/pi-ai";
import { createProvider } from "@earendil-works/pi-ai";
import { openAICompletionsApi } from "@earendil-works/pi-ai/api/openai-completions.lazy";
import { createModels } from "@earendil-works/pi-ai/models";
import { openrouterProvider } from "@earendil-works/pi-ai/providers/openrouter";
import {
	createRegistry,
	defineDoc,
	defineExtension,
	defineTool,
	GenerationTask,
	Harness,
	hook,
	section,
	UsageDoc,
} from "@earendil-works/pi-durable";
import { openNodeSqliteStorage } from "@earendil-works/pi-durable/storage/sqlite/node";

import { compileHints } from "./hints.ts";
import { SYSTEM_PROMPT, taskPrompt } from "./prompt.ts";

const run = promisify(execFile);

// Node's fetch multiplexes every request to a host over one HTTP/2 connection. With dozens of long
// streaming responses, streams stalled with no bytes until the 90 s timeout. Use a real pool instead.
// Batch-priced models (":batch", half price) may queue a request before the first byte arrives, so
// undici's 5-minute header/body timeouts are lifted; the harness stream timeout below bounds waits instead.
setGlobalDispatcher(new Agent({ allowH2: false, connections: 128, keepAliveTimeout: 30_000, headersTimeout: 0, bodyTimeout: 0 }));
const ROOT = new URL("../..", import.meta.url).pathname;
const BUILD = join(ROOT, "build/farm");
const PY = join(ROOT, "build/venv/bin/python");
const ctx = BACKGROUND_CONTEXT;
let MATCHES_DIR = join(ROOT, "matches");
let WORK_TAG = "main";

type Tier = {
	model: string;
	thinking?: "off" | "minimal" | "low" | "medium" | "high";
	maxAttempts: number;
	minSize?: number; // only functions whose size (bytes) is within [minSize, maxSize] use this tier
	maxSize?: number;
	maxOutput?: number; // OpenRouter output-token cap (thinking included); default CLOUD_MAX_OUTPUT
};
// Free OpenAI-compatible servers (LM Studio / llama.cpp / MLX / Ollama). farm/endpoints.json (gitignored):
//   { "big": { "baseUrl": "http://mac1:1234/v1", "apiKey": "...", "concurrency": 4 }, "small": { ... } }
// Tiers name their models "<endpoint>/<model id>". LOCAL_LLM_BASE_URL/LOCAL_LLM_API_KEY define "local".
type Endpoint = { baseUrl: string; apiKey?: string; concurrency?: number; thinking?: boolean; maxTokens?: number };

// Per-conversation job state, committed with the transcript.
type JobState = {
	addr: string;
	tier: number;
	attempts: number;
	maxAttempts: number;
	status: string; // running | match | exhausted
	bestScore: number;
	bestCode: string;
	bestReport: string;
	// One line per submission: score and the first mismatch, handed to later tiers.
	history?: { tier: number; n: number; score: number; note: string }[];
};
const Job = defineDoc<JobState>({
	kind: "hulk.job",
	version: 1,
	scope: "conversation",
	history: "latest",
	fork: "initial",
	initial: () => ({ addr: "", tier: 0, attempts: 0, maxAttempts: 0, status: "running", bestScore: -1, bestCode: "", bestReport: "", history: [] }),
});
// Session index: "addr:tier" -> conversation id, so a restart reattaches instead of starting over.
// Conversation IDs are numbers; early runs stored strings, so readers go through Number().
const Index = defineDoc<{ jobs: Record<string, number | string> }>({
	kind: "hulk.index",
	version: 1,
	scope: "session",
	initial: () => ({ jobs: {} }),
});

async function compare(src: string, addr: string): Promise<{ status: string; score?: number; report: string }> {
	try {
		const { stdout } = await run(PY, [join(ROOT, "tools/compare.py"), src, addr, "--json"], { timeout: 120_000 });
		return JSON.parse(stdout);
	} catch (e: any) {
		// compare.py exits 1 on a non-match but still prints JSON.
		if (e.stdout) return JSON.parse(e.stdout);
		return { status: "tool_error", report: String(e.message).slice(0, 500) };
	}
}

// Matches must come from real C++; inline asm or emitted bytes would "match" trivially.
const FORBIDDEN = /\b(__asm|_asm|asm|_emit|__emit)\b|naked|#\s*pragma/;

// Compact one-line description of how a submission failed.
function firstMismatch(r: { status: string; report: string }): string {
	if (r.status === "match") return "match";
	const lines = r.report.split("\n");
	if (r.status !== "diff") return `${r.status}: ${(lines[1] ?? "").trim()}`.slice(0, 140);
	const bytes = lines.find((l) => l.startsWith("bytes")) ?? "";
	const first = lines.find((l) => /^(!!|--|\+\+) /.test(l));
	const where = first ? first.slice(2).replace(/\s{2,}/g, " ").trim() : "no mismatched instruction (length differs)";
	return `${bytes.replace("bytes ", "")}; first mismatch ${where}`.slice(0, 160);
}

async function verifyRefs(src: string, addr: string): Promise<{ status: string; issues: string }> {
	try {
		const { stdout } = await run(PY, [join(ROOT, "tools/verify_relocs.py"), src, "--addr", addr, "--json"], { timeout: 120_000 });
		const v = JSON.parse(stdout);
		const SOFT = new Set(["vftable_of_other_class", "aliased_target", "call_target_not_known_function", "function_address_as_data"]);
		const hard = (v.issues ?? []).filter((i: [string, string]) => !SOFT.has(i[0]));
		return { status: v.status, issues: hard.map((i: [string, string]) => `${i[0]} ${i[1]}`).join("; ").slice(0, 400) };
	} catch (e: any) {
		return { status: "ok", issues: "" }; // never block a match on a checker failure
	}
}

const submitCpp = defineTool({
	name: "submit_cpp",
	description: "Compile a complete C++ translation unit with MSVC 7.1 and diff the best-matching function against the target.",
	parameters: Type.Object({ code: Type.String({ description: "Complete .cpp source" }) }),
	replay: "safe",
	executionMode: "sequential",
	execute: async (args, api, context) => {
		const job = (await api.snapshot(Job, api.conversationId, context))!;
		if (FORBIDDEN.test(args.code)) {
			return { content: [{ type: "text", text: "Rejected: inline assembly, _emit, naked functions and #pragma are not allowed. Write plain C++." }], isError: true };
		}
		const n = job.attempts + 1;
		const dir = join(BUILD, "work", WORK_TAG, job.addr);
		mkdirSync(dir, { recursive: true });
		const src = join(dir, `t${job.tier}_a${n}.cpp`);
		writeFileSync(src, args.code);
		const r = await compare(src, job.addr);
		if (r.status === "compile_error") r.report += compileHints(r.report);
		let refNote = "";
		if (r.status === "match") {
			// Same bytes with relocations masked; now check that strings, constants and targets are right too.
			const v = await verifyRefs(src, job.addr);
			if (v.status !== "ok") {
				r.status = "diff";
				r.score = 0.99;
				refNote = `Instruction bytes match, but references are wrong (${v.issues}). Fix the string literals / constants / which function or global each reference names.`;
				r.report = refNote;
			}
		}
		const score = r.status === "match" ? 1 : (r.score ?? 0);
		const matched = r.status === "match";
		const left = job.maxAttempts - n;
		await api.commit(async (tx) => {
			const j = await tx.doc(Job, api.conversationId);
			j.attempts = n;
			j.history = [...(j.history ?? []), { tier: job.tier, n, score, note: firstMismatch(r) }];
			if (score > j.bestScore) {
				j.bestScore = score;
				j.bestCode = args.code;
				j.bestReport = r.report;
			}
			if (matched) j.status = "match";
			else if (left <= 0) j.status = "exhausted";
		}, context);
		if (matched) {
			mkdirSync(MATCHES_DIR, { recursive: true });
			const dest = join(MATCHES_DIR, `${job.addr}.cpp`);
			copyFileSync(src, dest);
			// clang-format the saved match; the formatter re-verifies and keeps the original on any failure.
			await run(PY, [join(ROOT, "tools/format_matches.py"), dest, "--jobs", "1"], { timeout: 120_000 }).catch(() => {});
			return { content: [{ type: "text", text: "MATCH. Done." }], control: { terminate: true } };
		}
		if (left <= 0) {
			return { content: [{ type: "text", text: r.report + "\nNo submissions left." }], control: { terminate: true } };
		}
		return { content: [{ type: "text", text: `${r.report}\n(${left} submissions left)` }] };
	},
});

// If the model answers in prose instead of submitting, push it back to the tool a couple of times.
const nudges = new Map<string, number>();
const Decomp = defineExtension({
	name: "decomp",
	tools: [submitCpp],
	sections: [section("preamble", () => SYSTEM_PROMPT, { tag: false })],
	hooks: [
		hook(GenerationTask, {
			onYield: async (_answer, api, context) => {
				const job = await api.snapshot(Job, api.conversationId, context);
				if (!job || job.status !== "running" || job.attempts >= job.maxAttempts) return undefined;
				const k = (nudges.get(String(api.conversationId)) ?? 0) + 1;
				nudges.set(String(api.conversationId), k);
				return k <= 2 ? { continue: "Call submit_cpp with your next candidate." } : undefined;
			},
		}),
	],
});

function loadEndpoints(): Record<string, Endpoint> {
	const file = join(ROOT, "farm/endpoints.json");
	const eps: Record<string, Endpoint> = existsSync(file) ? JSON.parse(readFileSync(file, "utf8")) : {};
	if (process.env.LOCAL_LLM_BASE_URL && !eps.local) {
		eps.local = { baseUrl: process.env.LOCAL_LLM_BASE_URL, apiKey: process.env.LOCAL_LLM_API_KEY };
	}
	return eps;
}

function endpointProvider(name: string, ep: Endpoint, modelIds: string[]) {
	return createProvider({
		id: name,
		name,
		baseUrl: ep.baseUrl,
		// pi-ai treats an empty credential as "no API key"; keyless local servers ignore the placeholder.
		auth: { apiKey: { name: `${name} LLM`, resolve: async () => ({ auth: { apiKey: ep.apiKey ?? "local" } }) } },
		models: modelIds.map((id) => ({
			id, name: id, api: "openai-completions" as const, provider: name, baseUrl: ep.baseUrl,
			reasoning: true, input: ["text" as const],
			cost: { input: 0, output: 0, cacheRead: 0, cacheWrite: 0 },
			// Small local models can loop forever inside a tool argument; one C++ TU fits easily in 4k tokens.
			contextWindow: 131072, maxTokens: ep.maxTokens ?? 4096,
		})),
		api: openAICompletionsApi(),
	} as any);
}

class Semaphore {
	private waiters: (() => void)[] = [];
	private free: number;
	constructor(free: number) {
		this.free = free;
	}
	async run<T>(fn: () => Promise<T>): Promise<T> {
		if (this.free > 0) this.free--;
		else await new Promise<void>((r) => this.waiters.push(r));
		try {
			return await fn();
		} finally {
			const next = this.waiters.shift();
			if (next) next();
			else this.free++;
		}
	}
}

const ENDPOINTS = loadEndpoints();
const CLOUD_MAX_OUTPUT = 8192;
const MAX_OUTPUT_BY_MODEL = new Map<string, number>(); // OpenRouter model id -> tier maxOutput

// Local reasoning models ignore "low" effort and think for 20k+ tokens before acting. For endpoints
// with "thinking": false (the default), rewrite chat requests to disable thinking in the chat template.
{
	const noThink = Object.values(ENDPOINTS).filter((e) => e.thinking !== true).map((e) => e.baseUrl.replace(/\/$/, ""));
	const realFetch = globalThis.fetch;
	globalThis.fetch = async (input: any, init?: any) => {
		const url = typeof input === "string" ? input : input instanceof URL ? input.href : input.url;
		if (noThink.some((b) => url.startsWith(b)) && url.endsWith("/chat/completions") && typeof init?.body === "string") {
			const body = JSON.parse(init.body);
			body.chat_template_kwargs = { ...(body.chat_template_kwargs ?? {}), enable_thinking: false };
			delete body.reasoning_effort;
			delete body.reasoning;
			init = { ...init, body: JSON.stringify(body) };
		}
		// Cloud models occasionally degenerate into a repetition loop (one Luna turn emitted a 483 KB
		// "submission", 137k output tokens). Clamp output; keep room above any thinking budget.
		if (url.startsWith("https://openrouter.ai/") && typeof init?.body === "string") {
			const body = JSON.parse(init.body);
			const budget = body.thinking?.budget_tokens ?? 0;
			const cap = Math.max(MAX_OUTPUT_BY_MODEL.get(body.model) ?? CLOUD_MAX_OUTPUT, budget + 4096);
			for (const k of ["max_tokens", "max_completion_tokens"]) {
				if (typeof body[k] === "number" && body[k] > cap) body[k] = cap;
			}
			if (body.max_tokens === undefined && body.max_completion_tokens === undefined) body.max_tokens = cap;
			init = { ...init, body: JSON.stringify(body) };
		}
		return realFetch(input, init);
	};
}
// Local endpoints, and OpenRouter ":free" variants (rate-limited, ~1000 requests/day, no credit used).
const isFree = (model: string) => model.slice(0, model.indexOf("/")) in ENDPOINTS || model.endsWith(":free");

function parseModel(m: string) {
	const i = m.indexOf("/");
	return { provider: m.slice(0, i), modelId: m.slice(i + 1) };
}

async function main() {
	const { values } = parseArgs({
		options: {
			limit: { type: "string", default: "10" },
			concurrency: { type: "string", default: "4" },
			queue: { type: "string", default: join(BUILD, "queue.txt") },
			tiers: { type: "string", default: join(ROOT, "farm/tiers.json") },
			only: { type: "string" },
			db: { type: "string", default: join(BUILD, "farm.sqlite") },
			budget: { type: "string", default: "50" }, // USD, all-time across every ledger; free tiers ignore it
			bench: { type: "string" }, // isolated run: own ledger/db/matches dir, ignores existing matches
			lane: { type: "string" }, // parallel worker lane: own ledger/db, but writes to and skips main matches/
			packets: { type: "string", default: join(BUILD, "packets") }, // prebuilt packet dir (A/B tests)
		},
	});
	const tiers: Tier[] = JSON.parse(readFileSync(values.tiers!, "utf8"));
	for (const t of tiers) if (t.maxOutput) MAX_OUTPUT_BY_MODEL.set(parseModel(t.model).modelId, t.maxOutput);
	const sizes = new Map<string, number>();
	for (const line of readFileSync(join(ROOT, "build/functions.csv"), "utf8").split("\n").slice(1)) {
		const [a, size] = line.split(",");
		if (a) sizes.set("0x" + parseInt(a, 16).toString(16).padStart(8, "0"), Number(size));
	}
	const bench = values.bench;
	const lane = values.lane;
	if (bench && lane) throw new Error("--bench and --lane are exclusive");
	const ledgerPath = bench ? join(BUILD, "bench", `${bench}.jsonl`) : lane ? join(BUILD, "lanes", `${lane}.jsonl`) : join(BUILD, "results.jsonl");
	const matchesDir = bench ? join(BUILD, "bench", bench, "matches") : join(ROOT, "matches");
	const dbPath = bench ? join(BUILD, "bench", `${bench}.sqlite`) : lane ? join(BUILD, "lanes", `${lane}.sqlite`) : values.db!;
	mkdirSync(join(BUILD, "lanes"), { recursive: true });
	mkdirSync(join(BUILD, "bench"), { recursive: true });
	MATCHES_DIR = matchesDir;
	WORK_TAG = bench ?? (lane ? `lane-${lane}` : "main");

	// Finished (addr, tier) pairs from the ledger; matched addresses are skipped entirely.
	const finished = new Map<string, Set<number>>();
	const failures = new Map<string, number>(); // addr:tier -> earlier provider-error runs (new requestId each retry)
	const budget = Number(values.budget);
	let spent = 0;
	const benchDir = join(BUILD, "bench");
	const laneDir = join(BUILD, "lanes");
	for (const f of [join(BUILD, "results.jsonl"),
		...readdirSync(benchDir).filter((n) => n.endsWith(".jsonl")).map((n) => join(benchDir, n)),
		...readdirSync(laneDir).filter((n) => n.endsWith(".jsonl")).map((n) => join(laneDir, n))]) {
		if (!existsSync(f)) continue;
		for (const line of readFileSync(f, "utf8").split("\n")) if (line) spent += JSON.parse(line).cost ?? 0;
	}
	if (existsSync(ledgerPath)) {
		for (const line of readFileSync(ledgerPath, "utf8").split("\n")) {
			if (!line) continue;
			const r = JSON.parse(line);
			// Provider/model errors (timeouts, 429s) didn't really try the tier; retry it next run.
			if (r.status === "failed") {
				const k = `${r.addr}:${r.tier}`;
				failures.set(k, (failures.get(k) ?? 0) + 1);
				continue;
			}
			if (!finished.has(r.addr)) finished.set(r.addr, new Set());
			finished.get(r.addr)!.add(r.status === "match" ? -1 : r.tier);
		}
	}
	const spentAtStart = spent;
	// Matches demoted by reference verification: retried under fresh conversations.
	const invalidPath = join(BUILD, "invalid.txt");
	const invalid = new Set(existsSync(invalidPath) ? readFileSync(invalidPath, "utf8").split("\n").filter(Boolean) : []);
	for (const a of invalid) finished.delete(a);
	const isDone = (a: string) => existsSync(join(matchesDir, `${a}.cpp`)) || finished.get(a)?.has(-1)
		|| tiers.every((tier, t) => finished.get(a)?.has(t) || !fits(a, tier));

	const fits = (a: string, tier: Tier) => {
		const size = sizes.get(a) ?? 0;
		return size >= (tier.minSize ?? 0) && size <= (tier.maxSize ?? Infinity);
	};
	let queue = values.only
		? values.only.split(",")
		: readFileSync(values.queue!, "utf8").split("\n").filter(Boolean);
	queue = queue.map((a) => "0x" + parseInt(a, 16).toString(16).padStart(8, "0")).filter((a) => !isDone(a));
	queue = queue.slice(0, Number(values.limit));

	const models = createModels();
	models.setProvider(openrouterProvider());
	const limits = new Map<string, Semaphore>();
	for (const [name, ep] of Object.entries(ENDPOINTS)) {
		const ids = tiers.filter((t) => parseModel(t.model).provider === name).map((t) => parseModel(t.model).modelId);
		if (!ids.length) continue;
		models.setProvider(endpointProvider(name, ep, [...new Set(ids)]));
		limits.set(name, new Semaphore(ep.concurrency ?? 2));
	}
	for (const t of tiers) {
		const p = parseModel(t.model).provider;
		if (p !== "openrouter" && !ENDPOINTS[p]) throw new Error(`tier ${t.model}: unknown endpoint "${p}" (add it to farm/endpoints.json)`);
	}
	const registry = createRegistry();
	registry.install(Decomp);
	const harness = await Harness.open(await openNodeSqliteStorage(dbPath), {
		models,
		registry,
		settings: {
			extensions: [Decomp],
			stream: { timeoutMs: tiers.some((t) => t.model.endsWith(":batch")) ? 3_600_000 : 90_000 },
			retry: { maxRetries: 3 },
			compaction: { enabled: false },
			toolExecution: "sequential",
		},
	}, ctx);
	harness.resume();

	async function packet(addr: string): Promise<string> {
		const p = join(values.packets!, `${addr}.txt`);
		if (existsSync(p)) return readFileSync(p, "utf8");
		const { stdout } = await run(PY, [join(ROOT, "tools/packet.py"), "show", addr]);
		return stdout;
	}

	type Handoff = { code: string; report: string; history: NonNullable<JobState["history"]>; models: string[] };
	async function runTier(addr: string, t: number, previous?: Handoff) {
		const tier = tiers[t];
		const key = invalid.has(addr) ? `${addr}:${t}:refs` : `${addr}:${t}`;
		const index = await harness.snapshot(Index, ctx);
		let conv = index?.jobs[key] != null ? await harness.conversation(Number(index.jobs[key]) as any, ctx) : undefined;
		if (!conv) {
			conv = await harness.createConversation({
				ownership: { kind: "ownerless" },
				agent: { model: parseModel(tier.model), thinkingLevel: tier.thinking ?? "medium", extensions: [Decomp] },
				init: async (tx, id) => {
					Object.assign(await tx.doc(Job, id), { addr, tier: t, maxAttempts: tier.maxAttempts });
				},
			}, ctx);
			await harness.commit(async (tx) => {
				(await tx.doc(Index)).jobs[key] = conv!.id as unknown as number;
			}, ctx);
		}
		const started = Date.now();
		// Conversations can be resumed/retried, and pi.usage is cumulative per conversation:
		// record this run's own spend as (after - before), or retries get counted again.
		const sumUsage = (u: any) => {
			let c = 0, i = 0, o = 0, cr = 0;
			for (const m of Object.values(u?.models ?? {}) as any[]) {
				c += m.cost?.total ?? 0; i += m.input ?? 0; o += m.output ?? 0; cr += m.cacheRead ?? 0;
			}
			return { cost: c, input: i, output: o, cacheRead: cr };
		};
		const before = sumUsage(await harness.snapshot(UsageDoc, conv.id, ctx));
		const content = taskPrompt(await packet(addr), tier.maxAttempts, previous);
		const workDir = join(BUILD, "work", WORK_TAG, addr);
		mkdirSync(workDir, { recursive: true });
		writeFileSync(join(workDir, `t${t}_prompt.txt`), content);
		const retry = failures.get(key) ?? 0;
		const sub = await conv.submit({ type: "input", content, requestId: retry ? `${key}:retry${retry}` : key }, ctx);
		const settled = await sub.wait(ctx);
		const job = (await harness.snapshot(Job, conv.id, ctx))!;
		const usage = await harness.snapshot(UsageDoc, conv.id, ctx);
		const after = sumUsage(usage);
		const cost = after.cost - before.cost, input = after.input - before.input;
		const output = after.output - before.output, cacheRead = after.cacheRead - before.cacheRead;
		const status = job.status === "running" ? (settled.status === "done" ? "gave_up" : "failed") : job.status;
		const rec = {
			addr, tier: t, model: tier.model, status, attempts: job.attempts, bestScore: job.bestScore,
			cost: Number(cost.toFixed(5)), input, output, cacheRead, secs: Math.round((Date.now() - started) / 1000),
			...(settled.status === "unanswered"
				? { reason: (settled as any).reason, detail: JSON.stringify((settled as any).detail ?? null).slice(0, 300) }
				: {}),
		};
		appendFileSync(ledgerPath, JSON.stringify(rec) + "\n");
		if (status === "failed") failures.set(key, retry + 1);
		// 402 = the provider account is out of credits: stop paid tiers instead of failing every request.
		// 402 = out of credits; 403 "Budget limit exceeded" = the key's daily/weekly cap. Either way, stop paid tiers.
		const d = String(rec.detail ?? "");
		if (status === "failed" && !isFree(tier.model) && (/\b402\b/.test(d) || (/\b403\b/.test(d) && /limit|budget|permission/i.test(d)))) creditsOut = true;
		spent += rec.cost;
		console.log(`${addr} t${t} ${tier.model.padEnd(32)} ${status.padEnd(9)} att=${job.attempts} best=${job.bestScore.toFixed(2)} $${rec.cost} ${rec.secs}s`);
		return job;
	}

	// Everything earlier tiers tried for addr: best code/diff overall plus a line per attempt.
	async function handoff(addr: string, upTo: number): Promise<Handoff | undefined> {
		const index = await harness.snapshot(Index, ctx);
		const jobs: JobState[] = [];
		for (let t = 0; t < upTo; t++) {
			const id = index?.jobs[`${addr}:${t}`];
			const j = id != null ? await harness.snapshot(Job, Number(id) as any, ctx) : undefined;
			if (j) jobs.push(j as JobState);
		}
		const best = jobs.filter((j) => j.bestCode).sort((a, b) => b.bestScore - a.bestScore)[0];
		if (!best) return undefined;
		const clip = (t: string, n: number) => (t.length > n ? t.slice(0, n) + `\n/* ... ${t.length - n} more chars cut ... */` : t);
		return {
			code: clip(best.bestCode, 8000),
			report: clip(best.bestReport, 4000),
			history: jobs.flatMap((j) => j.history ?? []),
			models: jobs.map((j) => tiers[j.tier]?.model ?? "?"),
		};
	}

	async function work(addr: string) {
		let previous: Handoff | undefined;
		const size = sizes.get(addr) ?? 0;
		for (let t = 0; t < tiers.length; t++) {
			if (finished.get(addr)?.has(t)) continue;
			if (t > 0 && !previous) previous = await handoff(addr, t);
			if (size < (tiers[t].minSize ?? 0) || size > (tiers[t].maxSize ?? Infinity)) continue;
			if (!isFree(tiers[t].model) && (creditsOut || spent >= budget || keyRemaining - (spent - spentAtStart) < keyFloor)) {
				if (!budgetWarned) console.log(creditsOut
					? `budget reached: provider credits or key budget exhausted (402/403): skipping paid tiers`
					: spent >= budget
						? `budget $${budget} reached ($${spent.toFixed(2)} spent): skipping paid tiers`
						: `budget reached: OpenRouter key limit nearly used ($${(keyRemaining - (spent - spentAtStart)).toFixed(2)} left on the key): skipping paid tiers`);
				budgetWarned = true;
				continue;
			}
			try {
				const limit = limits.get(parseModel(tiers[t].model).provider);
				const job = limit ? await limit.run(() => runTier(addr, t, previous)) : await runTier(addr, t, previous);
				if (job.status === "match") return;
				if (job.status === "running") return; // provider error: retry this tier on a later run
				previous = await handoff(addr, t + 1);
			} catch (e: any) {
				console.error(`${addr} t${t} error: ${e?.message ?? e}`);
				return;
			}
		}
	}

	// OpenRouter's own accounting: the key's spend and remaining limit. Paid tiers stop near the limit.
	let keyRemaining = Infinity;
	try {
		const res = await fetch("https://openrouter.ai/api/v1/key", { headers: { Authorization: `Bearer ${process.env.OPENROUTER_API_KEY}` } });
		const d = (await res.json()).data;
		if (d?.limit_remaining != null) keyRemaining = d.limit_remaining;
		// The account balance can run out before the key's own limit does (402 "would exceed your available credits").
		const cr = (await (await fetch("https://openrouter.ai/api/v1/credits", { headers: { Authorization: `Bearer ${process.env.OPENROUTER_API_KEY}` } })).json()).data;
		if (cr?.total_credits != null) keyRemaining = Math.min(keyRemaining, cr.total_credits - cr.total_usage);
		console.log(`openrouter key: usage today $${d?.usage_daily?.toFixed?.(3)}, all-time $${d?.usage?.toFixed?.(3)}, remaining ${d?.limit_remaining ?? "unlimited"}, spendable $${keyRemaining.toFixed(2)}`);
	} catch (e: any) {
		console.log(`openrouter key check failed: ${e?.message ?? e}`);
	}
	const keyFloor = 0.5;
	let budgetWarned = false;
	let creditsOut = false;
	const concurrency = Number(values.concurrency);
	let next = 0;
	console.log(`farm: ${queue.length} functions, concurrency ${concurrency}, tiers ${tiers.map((t) => t.model).join(" -> ")}, budget $${budget} ($${spent.toFixed(3)} spent)`);
	await Promise.all(Array.from({ length: concurrency }, async () => {
		while (next < queue.length) await work(queue[next++]);
	}));
	const total = await harness.usage(ctx);
	let cost = 0;
	for (const u of Object.values(total.models) as any[]) cost += u.cost?.total ?? 0;
	console.log(`session total cost so far: $${cost.toFixed(4)}`);
	await harness.close(ctx);
}

await main();
