# Permutation Performance Benchmarking

This project benchmarks different permutation algorithms to compare their performance. The algorithms included are:
- Backtracking
- Depth-First Search (DFS)
- Factorial
- Heap's Algorithm
- Lexicographic Order

## Files

- `main.cpp`: Main file that runs the benchmarks.
- `backtracking.hpp`: Header file for the backtracking permutation algorithm.
- `dfs.hpp`: Header file for the DFS permutation algorithm.
- `factorial.hpp`: Header file for the factorial permutation algorithm.
- `heap.hpp`: Header file for the Heap's algorithm permutation.
- `lexicographic.hpp`: Header file for the Lexicographic Order permutation algorithm.

## Benchmark Results

The following table shows the benchmark results for different dataset sizes:

```
Dataset Size    backtracking (ms)   dfsPermute (ms)     factorialPermute (ms)   heapPermute (ms)    lexicographicOrder (ms)
---------------------------------------------------------------------------------------------------------------------------
1               0                   0                   0                       0                   0
2               0                   0                   0                       0                   0
3               0                   0                   0                       0                   0
4               0                   0                   0                       0                   0
5               0                   0                   0                       0                   0
6               0                   0                   0                       0                   0
7               7                   0                   0                       0                   0
8               91                  5                   3                       4                   5
9               827                 60                  50                      48                  11
10              8611                599                 496                     518                 58
11              130078              8691                7268                    6925                7044
```

## Analysis and Explanation

| Algorithm            | Pros                                                                 | Cons                                                                 |
|----------------------|----------------------------------------------------------------------|----------------------------------------------------------------------|
| **Backtracking**     | Simple to implement and understand                                   | Inefficient for larger datasets due to its exponential time complexity|
| **Depth-First Search (DFS)** | Efficient for smaller datasets, avoids redundant calculations | Still suffers from exponential time complexity for larger datasets   |
| **Factorial**        | Directly generates permutations using swaps, efficient for moderate dataset sizes | Still has exponential time complexity, but performs better than backtracking and DFS for larger datasets |
| **Heap's Algorithm** | Efficient and systematic, performs well for larger datasets          | Complexity increases with dataset size, but more manageable compared to other algorithms |
| **Lexicographic Order** | Simple and efficient for generating permutations in lexicographic order | Still has exponential time complexity, but performs well for moderate dataset sizes |

## Lessons Learned

- **Algorithm Selection**: The choice of permutation algorithm significantly impacts performance, especially for larger datasets. Heap's algorithm and Lexicographic Order are generally the most efficient for larger datasets.
- **Time Complexity**: All permutation algorithms have exponential time complexity, but their implementation details can lead to significant differences in performance.
- **Optimization**: Understanding the strengths and weaknesses of each algorithm helps in selecting the right one for specific use cases.

## Important Note

All the algorithms listed in this README have a theoretical time complexity of O(n!). This means that the execution time of these algorithms increases factorially as the size of the dataset increases. However, despite having the same theoretical time complexity, the practical performance of these algorithms can vary due to their implementation details and the number of recursive calls or swaps they perform.

## Personal Note

If I were to choose a permutation algorithm for production use, I would select the lexicographic order algorithm because:
- No recursion, making it easier to debug and understand.
- Fast and optimized.
- Clean and maintainable code.
- Flexible for solving various problems, such as finding the next permutation in lexicographic order.

## How to Run

1. Clone the repository.
2. Open the project in your preferred C++ development environment.
3. Build and run the project to see the benchmark results.

## Dependencies

- C++11 or higher
- Standard Template Library (STL)

## License

This project is licensed under the MIT License.
