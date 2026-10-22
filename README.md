# C++ Tasks

A collection of standalone C++17 exercises covering data structures, string algorithms, statistics, and lossless compression.

Each topic lives in its own directory and has a small `Makefile`. There is no shared build system, so examples can be built independently with `make -C <directory>`.

## Projects

| Directory | What it demonstrates |
| --- | --- |
| [`circular_linked_list`](circular_linked_list/) | Generic circular singly linked list with a sentinel node, iterators, insertion, removal, and clearing. |
| [`descriptive_statistics`](descriptive_statistics/) | Mean, median, standard deviation, quartiles, and outlier bounds for numeric data. |
| [`fibonacci_archiver`](fibonacci_archiver/) | File compression and decompression using Fibonacci coding. |
| [`string_search_algorithms`](string_search_algorithms/) | Naive search, KMP, Boyer–Moore, and `std::string::find` performance comparison. |
| [`trie_vs_hash_map`](trie_vs_hash_map/) | Word-frequency comparison between a trie and `std::unordered_map`. |

## Requirements

- A C++17-compatible compiler
- GNU Make

## Build an exercise

For example, build and run the linked-list demo:

```bash
make -C circular_linked_list
./circular_linked_list/a.out
```

The other exercises can be built in the same way:

```bash
make -C descriptive_statistics
make -C fibonacci_archiver
make -C string_search_algorithms
make -C trie_vs_hash_map
```

## Run the archiver

The archiver accepts a compression or decompression flag, an input path, and an output path:

```bash
./fibonacci_archiver/a.out -c input.txt compressed.bin
./fibonacci_archiver/a.out -d compressed.bin restored.txt
```

## Data-dependent exercises

`string_search_algorithms` and `trie_vs_hash_map` expect an `engwiki_ascii.txt` text corpus in their own directories. The corpus is intentionally ignored by Git because it is an external benchmark input.

```bash
./string_search_algorithms/a.out
./trie_vs_hash_map/a.out
```

## Notes

- The directories were named after the main algorithm or data structure they demonstrate so that the repository is easier to navigate.
- Build output is currently produced as `a.out` by the individual Makefiles.
- No license has been specified yet.

