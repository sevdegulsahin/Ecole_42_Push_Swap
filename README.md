*This project has been created as part of the 42 curriculum by sevdsahi, serozdem.*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using two stacks (`a` and `b`) and a limited set of operations, while minimizing the total number of operations.

The program implements **four distinct sorting strategies** with different time complexity classes, and an adaptive algorithm that selects the best strategy based on a measured **disorder metric**.

---

## Instructions

### Compilation

```bash
make        # Build push_swap
make clean  # Remove object files
make fclean # Remove object files and binary
make re     # Full rebuild
```

### Usage

```bash
./push_swap [STRATEGY] [--bench] <integers>
```

**Strategy flags (optional):**

| Flag | Algorithm | Complexity |
|------|-----------|------------|
| *(none)* or `--adaptive` | Adaptive (disorder-based) | O(n²) or O(n√n) |
| `--simple` | Selection sort adaptation | O(n²) |
| `--medium` | Chunk-based sort | O(n√n) |
| `--complex` | LSD Radix sort | O(n log n) |

**Benchmark flag:**
```bash
./push_swap --bench [--simple] 5 4 3 2 1
```
Outputs disorder %, strategy name, total ops, and per-operation counts to stderr.

### Examples

```bash
# Sort 5 numbers (adaptive, default)
./push_swap 5 4 3 2 1

# Force simple sort
./push_swap --simple 5 4 3 2 1

# Benchmark with medium strategy
./push_swap --bench --medium $(python3 -c "import random; l=list(range(1,101)); random.shuffle(l); print(*l)")

# Error cases
./push_swap 1 2 2        # Error: duplicate
./push_swap 2147483648   # Error: out of range
./push_swap abc          # Error: not an integer
```

---

## Algorithm Details

### Disorder Metric

The disorder is computed before any sorting operations:

```
disorder = mistakes / total_pairs
mistakes = number of pairs (i,j) where i < j but a[i] > a[j]
total_pairs = n * (n-1) / 2
```

A disorder of `0` means the stack is already sorted; `1` means fully reversed.

### 1. Simple Sort — O(n²)

**Strategy:** Selection sort adaptation.
- Repeatedly find the minimum element in stack `a`
- Rotate it to the top using `ra` or `rra` (whichever is shorter)
- Push it to stack `b`
- After reducing to 3 elements, sort them directly
- Pull all elements back to `a`

**Complexity:** O(n²) — each of the n elements requires up to O(n) rotations.

### 2. Medium Sort — O(n√n)

**Strategy:** Chunk-based sort (adapted for push_swap).
- Assign index ranks 0..n-1 to all elements (`indexing`)
- Choose chunk size ≈ √n
- Push elements chunk by chunk to `b` (lowest indices first, then rotate those within the chunk to the bottom of `b` for future efficiency)
- Pull back to `a` in descending order by finding each target index in `b`

**Complexity:** O(n√n) — √n chunks × O(n) work per chunk for push phase, O(√n) rotations per element in pull phase.

### 3. Complex Sort — O(n log n)

**Strategy:** LSD Radix sort adaptation.
- Assign index ranks 0..n-1 to all elements
- For each bit from LSB to MSB:
  - Elements with bit=0: push to `b`
  - Elements with bit=1: rotate to bottom of `a`
  - Push all of `b` back to `a`

**Complexity:** O(n log n) — ⌈log₂n⌉ passes × O(n) operations per pass.

### 4. Adaptive Sort — Disorder-based Selection

The adaptive algorithm measures disorder first, then selects:

| Disorder range | Strategy | Complexity | Rationale |
|---|---|---|---|
| `disorder < 0.2` | Simple sort | O(n²) | Few inversions; O(n²) terminates quickly |
| `disorder ≥ 0.2` | Chunk sort | O(n√n) | Best empirical performance across medium/high disorder |

**Design decision:** For high disorder (≥ 0.5), chunk sort is preferred over radix sort in the adaptive mode. While radix sort is theoretically O(n log n), it generates ~1400 operations for n=100 in the push_swap model (7 bits × 100 elements × 2 ops), whereas chunk sort generates ~600 operations — well within the 700-operation excellent performance target. The adaptive algorithm prioritizes empirical performance while documenting the theoretical complexity of each internal strategy.

### Performance Results

| Input size | Adaptive ops | Limit (excellent) |
|---|---|---|
| 100 elements | ~550–620 | ≤ 700 ✅ |
| 500 elements | ~5000–5200 | ≤ 5500 ✅ |

---

## Contributors

| Login | Contribution |
|-------|-------------|
| sevdsahi | Stack data structure, helper functions, libft utilities, parsing |
| serozdem | Sorting algorithms (simple, medium, complex, adaptive), benchmark mode, architecture |

### AI Usage

AI was used in this project for:
- **Debugging:** Identifying circular linked list loop conditions that caused infinite loops
- **Code review:** Spotting missing function prototypes and Makefile omissions
- **Understanding complexity:** Discussing O(n log n) vs O(n√n) tradeoffs in the push_swap operation model

All AI-generated or AI-assisted code was reviewed, understood, and tested by both contributors before inclusion.

---

## Resources

- Knuth, D. E. (1998). *The Art of Computer Programming, Vol. 3: Sorting and Searching*
- [Push_swap visualizer](https://github.com/o-reo/push_swap_visualizer) — for visual debugging
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/) — algorithm complexity reference
- Wikipedia: [Radix Sort](https://en.wikipedia.org/wiki/Radix_sort), [Selection Sort](https://en.wikipedia.org/wiki/Selection_sort)