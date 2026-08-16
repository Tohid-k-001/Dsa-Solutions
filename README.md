# LeetCode DSA Solutions

A practice-oriented collection of my LeetCode solutions, organized by
**problem-solving pattern** rather than only by problem number.

The goal of this README is simple: if you are learning DSA, pick a topic
below and practice the problems in **increasing problem-number order**.
Each problem links directly to the solution file in this repository.

> **Repository:** DSA / LeetCode Solutions\
> **Languages:** C++ and Python\
> **Focus:** Arrays, Hashing, Sliding Window, Two Pointers, XOR, DP,
> Graphs, Trees, Greedy, Math, and advanced data structures.

------------------------------------------------------------------------

## 🧭 How to Use This Repository

If you are a beginner, don't randomly jump between problems.

A better approach is:

1.  Pick **one pattern**.
2.  Solve the problems in that section from top to bottom.
3.  Try the problem yourself before opening the solution.
4.  After solving, identify **why that pattern works**.
5.  Revisit the same pattern with a harder problem.

### Recommended learning order

``` text
Arrays & Hashing
        ↓
Two Pointers
        ↓
Sliding Window
        ↓
Stack / Heap
        ↓
Bit Manipulation & XOR
        ↓
Greedy
        ↓
Binary Search
        ↓
Dynamic Programming
        ↓
Graphs
        ↓
Advanced Data Structures
```

------------------------------------------------------------------------

# 📚 Problems by Pattern

## 1. Arrays & Hashing

Start here if you are learning `unordered_map`, `unordered_set`,
frequency counting, ranking, duplicates, and lookup-based solutions.

  ------------------------------------------------------------------------------
                     \# Problem          Main Pattern     Solution
  --------------------- ---------------- ---------------- ----------------------
                      1 Two Sum          Hash Map         [1.cpp](1.cpp)

                    128 Longest          Hash Set         [128.cpp](128.cpp)
                        Consecutive                       
                        Sequence                          

                   1331 Rank Transform   Sorting + Hash   [1331.cpp](1331.cpp)
                        of an Array      Map              

                    169 Majority Element Frequency /      [169.cpp](169.cpp)
                                         Array            

                    217 Contains         Hash Set         [217.cpp](217.cpp)
                        Duplicate                         

                    242 Valid Anagram    Frequency Map    [242.cpp](242.cpp)

                    268 Missing Number   Array + Math     [268.cpp](268.cpp)

                    287 Find the         Array / Value    [287.cpp](287.cpp)
                        Duplicate Number Tracking         

                   2996 Smallest Missing Hash Set         [2996.cpp](2996.cpp)
                        Integer Greater                   
                        Than Sequential                   
                        Prefix Sum                        

                    349 Intersection of  Hash Set         [349.cpp](349.cpp)
                        Two Arrays                        

                   3731 Find Missing     Hash Set +       [3731.cpp](3731.cpp)
                        Elements         Sorting          

                    387 First Unique     Frequency Map    [387.cpp](387.cpp)
                        Character in a                    
                        String                            

                    389 Find the         Frequency / XOR  [389.cpp](389.cpp)
                        Difference                        

                    448 Find All Numbers In-place Marking [448.cpp](448.cpp)
                        Disappeared in                    
                        an Array                          
  ------------------------------------------------------------------------------

### Skills to learn

-   `unordered_map`
-   `unordered_set`
-   Frequency counting
-   Lookup in `O(1)` average time
-   Sorting + mapping
-   In-place array marking

------------------------------------------------------------------------

## 2. Sliding Window

This is one of the most important patterns in this repository.

Learn to recognize:

``` cpp
left
right
window condition
```

  ------------------------------------------------------------------------------
                     \# Problem          Main Pattern     Solution
  --------------------- ---------------- ---------------- ----------------------
                      3 Longest          Variable         [3.cpp](3.cpp)
                        Substring        Window + Hash    
                        Without          Map              
                        Repeating                         
                        Characters                        

                    209 Minimum Size     Variable Window  [209.cpp](209.cpp)
                        Subarray Sum                      

                    643 Maximum Average  Fixed Window     [643.cpp](643.cpp)
                        Subarray I                        

                    904 Fruit Into       At Most 2        [904.cpp](904.cpp)
                        Baskets          Distinct         

                   1004 Max Consecutive  At Most K Zeros  [1004.cpp](1004.cpp)
                        Ones III                          

                   1456 Maximum Number   Fixed Window     [1456.cpp](1456.cpp)
                        of Vowels in a                    
                        Substring of                      
                        Given Length                      

                   2461 Maximum Sum of   Fixed Window +   [2461.cpp](2461.cpp)
                        Distinct         Hash Map         
                        Subarrays With                    
                        Length K                          

                   2958 Length of        Variable         [2958.cpp](2958.cpp)
                        Longest Subarray Window +         
                        With at Most K   Frequency        
                        Frequency                         

                   3090 Maximum Length   Variable         [3090.cpp](3090.cpp)
                        Substring With   Window +         
                        Two Occurrences  Frequency        

                   3499 Maximize Active  String           [3499.cpp](3499.cpp)
                        Section with     Run/Window       
                        Trade I          Observation      
  ------------------------------------------------------------------------------

### Key templates

**Maximum valid window**

``` cpp
while (window is invalid) {
    remove nums[left];
    left++;
}

ans = max(ans, right - left + 1);
```

**Minimum valid window**

``` cpp
while (window is valid) {
    ans = min(ans, right - left + 1);
    remove nums[left];
    left++;
}
```

------------------------------------------------------------------------

## 3. Two Pointers / Sorted Arrays

Use this section to learn how two indices can replace nested loops.

  ------------------------------------------------------------------------------
                     \# Problem          Main Pattern     Solution
  --------------------- ---------------- ---------------- ----------------------
                      4 Median of Two    Merge / Two      [4.cpp](4.cpp)
                        Sorted Arrays    Pointers         

                     11 Container With   Two Pointers     [11.cpp](11.cpp)
                        Most Water                        

                   1790 Check if One     Two-Pointer      [1790.cpp](1790.cpp)
                        String Swap Can  Style Comparison 
                        Make Strings                      
                        Equal                             

                    628 Maximum Product  Extreme Values / [628.CPP](628.CPP)
                        of Three Numbers Sorting Logic    

                    633 Sum of Square    Two Pointers     [633.cpp](633.cpp)
                        Numbers                           

                   3867 Sum of GCD of    Sort + Two       [3867.cpp](3867.cpp)
                        Formed Pairs     Pointers + GCD   
  ------------------------------------------------------------------------------

------------------------------------------------------------------------

## 4. Bit Manipulation & XOR

This section is especially useful for learning XOR patterns.

  ------------------------------------------------------------------------------
                     \# Problem          Main Pattern     Solution
  --------------------- ---------------- ---------------- ----------------------
                    136 Single Number    XOR Cancellation [136.cpp](136.cpp)

                   1442 Count Triplets   Prefix XOR       [1442.cpp](1442.cpp)
                        That Can Form                     
                        Two Arrays of                     
                        Equal XOR                         

                   1486 XOR Operation in XOR              [1486.cpp](1486.cpp)
                        an Array                          

                    260 Single Number    XOR + Set Bit    [260.cpp](260.cpp)
                        III              Partitioning     

                   3514 Number of Unique XOR State DP     [3514.cpp](3514.cpp)
                        XOR Triplets II                   
  ------------------------------------------------------------------------------

### XOR progression

``` text
136
 ↓
1486
 ↓
389
 ↓
260
 ↓
1442
 ↓
3514
```

Important XOR ideas: - `x ^ x = 0` - `x ^ 0 = x` - XOR is associative -
XOR is useful for cancellation - Prefix XOR can turn range-XOR
conditions into lookup problems

------------------------------------------------------------------------

## 5. Strings

  ---------------------------------------------------------------------------------
                     \# Problem             Main Pattern     Solution
  --------------------- ------------------- ---------------- ----------------------
                      6 Zigzag Conversion   String           [6.cpp](6.cpp)
                                            Simulation       

                      7 Reverse Integer     Digit Processing [7.cpp](7.cpp)

                      8 String to Integer   Parsing +        [8.cpp](8.cpp)
                        (atoi)              Overflow         

                   1081 Smallest            Greedy +         [1081.cpp](1081.cpp)
                        Subsequence of      Monotonic Stack  
                        Distinct Characters                  

                   1291 Sequential Digits   Enumeration      [1291.cpp](1291.cpp)

                   3014 Minimum Number of   Greedy /         [3014.cpp](3014.cpp)
                        Pushes to Type Word Counting         
                        I                                    

                   3016 Minimum Number of   Frequency +      [3016.cpp](3016.cpp)
                        Pushes to Type Word Greedy           
                        II                                   

                   3302 Find the            Greedy +         [3302.cpp](3302.cpp)
                        Lexicographically   Prefix/Suffix    
                        Smallest Valid      Matching         
                        Sequence                             

                   3517 Smallest            Counting +       [3517.cpp](3517.cpp)
                        Palindromic         Sorting          
                        Rearrangement I                      

                   3518 Smallest            Counting +       [3518.cpp](3518.cpp)
                        Palindromic         Combinatorics    
                        Rearrangement II                     
  ---------------------------------------------------------------------------------

------------------------------------------------------------------------

## 6. Stack / Monotonic Stack

  ------------------------------------------------------------------------------
                     \# Problem          Main Pattern     Solution
  --------------------- ---------------- ---------------- ----------------------
                    496 Next Greater     Monotonic Stack  [496.cpp](496.cpp)
                        Element I                         

                   1081 Smallest         Monotonic        [1081.cpp](1081.cpp)
                        Subsequence of   Stack + Greedy   
                        Distinct                          
                        Characters                        
  ------------------------------------------------------------------------------

### Core idea

When you see:

``` text
next greater
next smaller
previous greater
previous smaller
```

think:

``` text
Monotonic Stack
```

------------------------------------------------------------------------

## 7. Heap / Priority Queue

  ----------------------------------------------------------------------------
                     \# Problem          Main Pattern     Solution
  --------------------- ---------------- ---------------- --------------------
                    215 Kth Largest      Priority Queue   [215.cpp](215.cpp)
                        Element in an                     
                        Array                             

  ----------------------------------------------------------------------------

This is a good starting point for: - Min heap - Max heap - Top-K
problems - `priority_queue`

------------------------------------------------------------------------

## 8. Binary Search / Search on Answer

  ------------------------------------------------------------------------------
                     \# Problem          Main Pattern     Solution
  --------------------- ---------------- ---------------- ----------------------
                   3312 Sorted GCD Pair  Binary Search +  [3312.cpp](3312.cpp)
                        Queries          Number Theory    

                   3345 Smallest         Search / Brute   [3345.cpp](3345.cpp)
                        Divisible Digit  Force            
                        Product I                         

                   3620 Network Recovery Binary Search on [3620.cpp](3620.cpp)
                        Pathways         Answer + DAG     
  ------------------------------------------------------------------------------

### Important concept

Binary search is not only:

``` cpp
binary search in a sorted array
```

It can also be:

``` text
Binary Search on Answer
```

when you can define:

``` text
possible(x) = true / false
```

------------------------------------------------------------------------

## 9. Dynamic Programming

  ------------------------------------------------------------------------------
                     \# Problem          Main Pattern     Solution
  --------------------- ---------------- ---------------- ----------------------
                     10 Regular          Memoization / DP [10.cpp](10.cpp)
                        Expression                        
                        Matching                          

                   1301 Number of Paths  Grid DP          [1301.cpp](1301.cpp)
                        with Max Score                    

                   3336 Find the Number  State DP + GCD   [3336.cpp](3336.cpp)
                        of Subsequences                   
                        With Equal GCD                    
  ------------------------------------------------------------------------------

### DP questions to ask

For every DP problem, try to identify:

``` text
1. What does dp[state] mean?
2. What are the choices?
3. What is the transition?
4. What is the base case?
5. What is the final state?
```

------------------------------------------------------------------------

## 10. Game Theory / Game DP

  ------------------------------------------------------------------------------
                     \# Problem          Main Pattern     Solution
  --------------------- ---------------- ---------------- ----------------------
                    486 Predict the      Interval DP /    [486.cpp](486.cpp)
                        Winner           Game Theory      

                    877 Stone Game       Game Theory      [877.cpp](877.cpp)
                                         Observation      

                   1140 Stone Game II    Game DP +        [1140.cpp](1140.cpp)
                                         Memoization      

                   1406 Stone Game III   DP / Score       [1406.cpp](1406.cpp)
                                         Difference       

                   1510 Stone Game IV    DP + Perfect     [1510.cpp](1510.cpp)
                                         Squares          

                   2029 Stone Game IX    Modulo 3 + Game  [2029.cpp](2029.cpp)
                                         Theory           
  ------------------------------------------------------------------------------

### Recommended game-theory progression

``` text
877 → 486 → 1510 → 1406 → 1140 → 2029
```

------------------------------------------------------------------------

## 11. Greedy

  ------------------------------------------------------------------------------
                     \# Problem          Main Pattern     Solution
  --------------------- ---------------- ---------------- ----------------------
                   1464 Maximum Product  Track Largest    [1464.cpp](1464.cpp)
                        of Two Elements  Values           
                        in an Array                       

                   3348 Smallest         Greedy + Number  [3348.cpp](3348.cpp)
                        Divisible Digit  Theory           
                        Product II                        

                   3499 Maximize Active  Greedy + Run     [3499.cpp](3499.cpp)
                        Section with     Lengths          
                        Trade I                           
  ------------------------------------------------------------------------------

------------------------------------------------------------------------

## 12. Graphs

  ------------------------------------------------------------------------------
                     \# Problem          Main Pattern     Solution
  --------------------- ---------------- ---------------- ----------------------
                   2685 Count the Number DFS + Connected  [2685.cpp](2685.cpp)
                        of Complete      Components       
                        Components                        

                   3286 Find a Safe Walk 0-1 BFS          [3286.py](3286.py)
                        Through a Grid                    

                   3310 Remove Methods   BFS / Graph      [3310.cpp](3310.cpp)
                        From Project     Reachability     

                   3532 Path Existence   Components /     [3532.cpp](3532.cpp)
                        Queries in a     Connectivity     
                        Graph I                           

                   3634 Minimum Removals Sorting +        [3634.cpp](3634.cpp)
                        to Balance Array Sliding Window   
  ------------------------------------------------------------------------------

> `3634.cpp` is included here because it is part of the newer
> graph/query-oriented practice set in this repository, although the
> implementation itself is primarily **sorting + sliding window**.

------------------------------------------------------------------------

## 13. Matrix

  ------------------------------------------------------------------------------
                     \# Problem          Main Pattern     Solution
  --------------------- ---------------- ---------------- ----------------------
                     36 Valid Sudoku     Matrix + Hashing [36.cpp](36.cpp)

                     73 Set Matrix       Matrix + Sets    [73.cpp](73.cpp)
                        Zeroes                            

                   1260 Shift 2D Grid    Matrix Index     [1260.cpp](1260.cpp)
                                         Mapping          

                   1301 Number of Paths  Grid DP          [1301.cpp](1301.cpp)
                        with Max Score                    
  ------------------------------------------------------------------------------

------------------------------------------------------------------------

## 14. Segment Tree / Advanced Data Structures

  ------------------------------------------------------------------------------
                     \# Problem          Main Pattern     Solution
  --------------------- ---------------- ---------------- ----------------------
                   2213 Longest          Segment Tree     [2213.cpp](2213.cpp)
                        Substring of One                  
                        Repeating                         
                        Character                         

                    705 Design HashSet   Data Structure   [705.cpp](705.cpp)
                                         Design           
  ------------------------------------------------------------------------------

------------------------------------------------------------------------

## 15. Math / Number Theory / Prefix Techniques

  ------------------------------------------------------------------------------
                     \# Problem          Main Pattern     Solution
  --------------------- ---------------- ---------------- ----------------------
                   3756 Concatenate      Prefix Sum +     [3756.cpp](3756.cpp)
                        Non-Zero Digits  Modular          
                        and Multiply by  Arithmetic       
                        Sum II                            

                   3867 Sum of GCD of    GCD + Sorting    [3867.cpp](3867.cpp)
                        Formed Pairs                      
  ------------------------------------------------------------------------------

------------------------------------------------------------------------

# 🗂️ Complete Problem Index

For quick navigation, here are all **72 numbered LeetCode files**
currently in the repository, sorted by problem number:

      \# Solution
  ------ ----------------------
       1 [1.cpp](1.cpp)
       3 [3.cpp](3.cpp)
       4 [4.cpp](4.cpp)
       6 [6.cpp](6.cpp)
       7 [7.cpp](7.cpp)
       8 [8.cpp](8.cpp)
      10 [10.cpp](10.cpp)
      11 [11.cpp](11.cpp)
      36 [36.cpp](36.cpp)
      73 [73.cpp](73.cpp)
     128 [128.cpp](128.cpp)
     136 [136.cpp](136.cpp)
     169 [169.cpp](169.cpp)
     209 [209.cpp](209.cpp)
     215 [215.cpp](215.cpp)
     217 [217.cpp](217.cpp)
     242 [242.cpp](242.cpp)
     260 [260.cpp](260.cpp)
     268 [268.cpp](268.cpp)
     287 [287.cpp](287.cpp)
     349 [349.cpp](349.cpp)
     387 [387.cpp](387.cpp)
     389 [389.cpp](389.cpp)
     448 [448.cpp](448.cpp)
     486 [486.cpp](486.cpp)
     496 [496.cpp](496.cpp)
     628 [628.CPP](628.CPP)
     633 [633.cpp](633.cpp)
     643 [643.cpp](643.cpp)
     705 [705.cpp](705.cpp)
     877 [877.cpp](877.cpp)
     904 [904.cpp](904.cpp)
    1004 [1004.cpp](1004.cpp)
    1081 [1081.cpp](1081.cpp)
    1140 [1140.cpp](1140.cpp)
    1260 [1260.cpp](1260.cpp)
    1291 [1291.cpp](1291.cpp)
    1301 [1301.cpp](1301.cpp)
    1331 [1331.cpp](1331.cpp)
    1406 [1406.cpp](1406.cpp)
    1442 [1442.cpp](1442.cpp)
    1456 [1456.cpp](1456.cpp)
    1464 [1464.cpp](1464.cpp)
    1486 [1486.cpp](1486.cpp)
    1510 [1510.cpp](1510.cpp)
    1790 [1790.cpp](1790.cpp)
    2029 [2029.cpp](2029.cpp)
    2213 [2213.cpp](2213.cpp)
    2461 [2461.cpp](2461.cpp)
    2685 [2685.cpp](2685.cpp)
    2958 [2958.cpp](2958.cpp)
    2996 [2996.cpp](2996.cpp)
    3014 [3014.cpp](3014.cpp)
    3016 [3016.cpp](3016.cpp)
    3090 [3090.cpp](3090.cpp)
    3286 [3286.py](3286.py)
    3302 [3302.cpp](3302.cpp)
    3310 [3310.cpp](3310.cpp)
    3312 [3312.cpp](3312.cpp)
    3336 [3336.cpp](3336.cpp)
    3345 [3345.cpp](3345.cpp)
    3348 [3348.cpp](3348.cpp)
    3499 [3499.cpp](3499.cpp)
    3514 [3514.cpp](3514.cpp)
    3517 [3517.cpp](3517.cpp)
    3518 [3518.cpp](3518.cpp)
    3532 [3532.cpp](3532.cpp)
    3620 [3620.cpp](3620.cpp)
    3634 [3634.cpp](3634.cpp)
    3731 [3731.cpp](3731.cpp)
    3756 [3756.cpp](3756.cpp)
    3867 [3867.cpp](3867.cpp)

------------------------------------------------------------------------

# 🌳 Binary Tree Practice

There is also a standalone binary-tree practice file:

-   [Binery_Tree.cpp](Binery_Tree.cpp)

It contains: - Binary tree construction from preorder - Preorder
traversal - Inorder traversal - Postorder traversal - Level-order
traversal

This file is **practice code**, not a numbered LeetCode solution.

------------------------------------------------------------------------

# 🧪 Other Files

-   `test.cpp` --- testing / scratch file
-   `.vscode/` --- VS Code configuration

------------------------------------------------------------------------

# 🎯 Suggested Practice Roadmap

If you are using this repository to learn DSA from scratch, follow this
sequence:

### Phase 1 --- Arrays & Hashing

``` text
1 → 217 → 242 → 169 → 128 → 287 → 448
```

### Phase 2 --- Two Pointers

``` text
4 → 11 → 633
```

### Phase 3 --- Sliding Window

``` text
643 → 209 → 3 → 904 → 1004 → 1456 → 2461 → 2958 → 3090
```

### Phase 4 --- XOR / Bit Manipulation

``` text
136 → 1486 → 389 → 260 → 1442 → 3514
```

### Phase 5 --- Stack / Heap

``` text
496 → 215 → 1081
```

### Phase 6 --- Greedy / Math

``` text
1464 → 3014 → 3016 → 1291 → 3345
```

### Phase 7 --- Dynamic Programming

``` text
10 → 1301 → 3336
```

### Phase 8 --- Game Theory

``` text
877 → 486 → 1510 → 1406 → 1140 → 2029
```

### Phase 9 --- Graphs

``` text
2685 → 3286 → 3310 → 3532 → 3620
```

### Phase 10 --- Advanced Problems

``` text
2213 → 3312 → 3348 → 3518 → 3756 → 3867
```

------------------------------------------------------------------------

# 💡 Pattern Recognition Cheat Sheet

  If you see...                            Think...
  ---------------------------------------- -------------------------
  Find pair / complement                   Hash Map
  Duplicate / frequency                    Hash Map / Hash Set
  Longest contiguous subarray              Sliding Window
  At most K                                Sliding Window
  Fixed length K                           Fixed Sliding Window
  Sorted array + two ends                  Two Pointers
  Next greater element                     Monotonic Stack
  Top K / Kth largest                      Heap
  XOR cancellation                         XOR
  Two numbers appear once                  XOR + Set Bit
  Repeated game choices                    Game Theory / DP
  `dp[i]` / state transitions              Dynamic Programming
  Connected components                     DFS / BFS / DSU
  Minimum/maximum feasible value           Binary Search on Answer
  Range updates / dynamic string queries   Segment Tree
  GCD / divisibility                       Number Theory
  Grid paths                               Matrix DP / BFS
  Frequency-based string construction      Counting + Greedy

------------------------------------------------------------------------

## ⭐ Goal of This Repository

This repository is not just a collection of answers.

The real goal is to build the ability to look at a new problem and
think:

``` text
What pattern does this problem belong to?
        ↓
What data structure fits that pattern?
        ↓
What invariant should I maintain?
        ↓
Can I reduce O(n²) to O(n)?
```

**Practice the pattern, not just the problem.**
