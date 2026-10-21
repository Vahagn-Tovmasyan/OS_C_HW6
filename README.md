# HW06: Data Alignment and Struct Padding in C

**Student:** Vahagn Tovmasyan  
**Server:** `ubuntu-aua-2026`  
**Compiler:** GCC  
**Directory:** `~/hw06`

## Assignment 1: Data Alignment

Compiled and executed:

```bash
gcc assignment1.c -o assignment1
./assignment1
```

### Results

| Type | Size (bytes) | Alignment (bytes) | Address |
|---|---:|---:|---|
| `int` | 4 | 4 | `0x7ffe1d3cfbdc` |
| `char` | 1 | 1 | `0x7ffe1d3cfbd9` |
| `double` | 8 | 8 | `0x7ffe1d3cfbe0` |
| `short` | 2 | 2 | `0x7ffe1d3cfbda` |

Each address satisfies its type's alignment requirement: `int` is aligned to 4 bytes, `double` to 8 bytes, and `short` to 2 bytes. A `char` can start at any byte address.

The variables were not stored in declaration order. The compiler can arrange separate local variables while respecting their alignment requirements.

## Assignment 2: Struct Padding

Compiled and executed:

```bash
gcc assignment2.c -o assignment2
./assignment2
```

### Results

| Field order | Field addresses in that order | Offsets | Size |
|---|---|---|---:|
| `char, int, double` | `0x7ffd8d665fc0`, `0x7ffd8d665fc4`, `0x7ffd8d665fc8` | 0, 4, 8 | 16 bytes |
| `double, int, char` | `0x7ffd8d665fd0`, `0x7ffd8d665fd8`, `0x7ffd8d665fdc` | 0, 8, 12 | 16 bytes |
| `char, double, int` | `0x7ffd8d665fe0`, `0x7ffd8d665fe8`, `0x7ffd8d665ff0` | 0, 8, 16 | 24 bytes |

The fields contain 13 bytes of data. In the original order, 3 padding bytes appear after `char`. Reordering to `double, int, char` moves these 3 bytes to the end, so the size remains 16 bytes.

The additional order `char, double, int` requires 7 padding bytes after `char` and 4 at the end, increasing the size to 24 bytes.

Padding aligns fields and rounds the struct size to a multiple of its alignment, allowing array elements to remain aligned. Rearranging fields can reduce padding, but does not always reduce size.

## Assignment 3: `#pragma pack`

Compiled and executed:

```bash
gcc assignment3.c -o assignment3
./assignment3
```

### Results

All versions use the field order `char a; int b; double c;`.

| Packing | Size | Alignment | Offsets (`a`, `b`, `c`) | Padding |
|---|---:|---:|---|---:|
| Default | 16 | 8 | 0, 4, 8 | 3 |
| `pack(1)` | 13 | 1 | 0, 1, 5 | 0 |
| `pack(2)` | 14 | 2 | 0, 2, 6 | 1 |
| `pack(4)` | 16 | 4 | 0, 4, 8 | 3 |

All values above are in bytes.

| Packing | Address of `a` | Address of `b` | Address of `c` |
|---|---|---|---|
| Default | `0x7ffc0853b1e0` | `0x7ffc0853b1e4` | `0x7ffc0853b1e8` |
| `pack(1)` | `0x7ffc0853b1c5` | `0x7ffc0853b1c6` | `0x7ffc0853b1ca` |
| `pack(2)` | `0x7ffc0853b1d2` | `0x7ffc0853b1d4` | `0x7ffc0853b1d8` |
| `pack(4)` | `0x7ffc0853b1f0` | `0x7ffc0853b1f4` | `0x7ffc0853b1f8` |

`pack(1)` removes all padding and saves 3 bytes. `pack(2)` leaves one padding byte and saves 2 bytes. `pack(4)` keeps the original size but reduces the struct's required alignment to 4 bytes.

Packing changes alignment constraints, not individual data type sizes. It can save memory but may produce unaligned fields and less efficient access. In the `pack(1)` result, `int` and `double` do not satisfy their normal alignment requirements.

These results describe the tested server. Absolute addresses may change between runs.

<img width="519" height="79" alt="image" src="https://github.com/user-attachments/assets/0b11b8eb-2e7f-4021-9f12-2e55b2bfbbaa" />

<img width="354" height="255" alt="image" src="https://github.com/user-attachments/assets/c239ed79-8a2d-430b-86c5-9b55fc5e176b" />

<img width="433" height="361" alt="image" src="https://github.com/user-attachments/assets/9bb28c4e-8486-4c44-a5d5-9d9ba5a68efb" />


