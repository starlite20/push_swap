***This project has been created as part of the 42 curriculum by ssujaude.***

## Description

Push_swap is a program focused on sorting a stack of integers using two stacks with a limited set of operations. The challenge lies in finding the most efficient way to sort with the minimum number of moves using only the moves allowed.

This project has a dual approach manner to identify the most effient way to sort. For smaller stacks with 5 or less elements, hardcoded algorithms are used for best performance. For stacks with more than 5 elements, the **Turk Sort** is used. This way, for larger number of elements, the cost of moving each element is calculated, and the cheapest path is chosen. 

---

### Allowed Operations

#### Swap Operations
- `sa` - Swap top two elements of Stack A
- `sb` - Swap top two elements of Stack B
- `ss` - Do both sa and sb simultaneously

#### Push Operations
- `pa` - Push top element from Stack B to Stack A
- `pb` - Push top element from Stack A to Stack B

#### Rotate Operations
- `ra` - Rotate Stack A 
- `rb` - Rotate Stack B
- `rr` - Do both ra and rb simultaneously

#### Reverse Rotate Operations
- `rra` - Reverse rotate Stack A
- `rrb` - Reverse rotate Stack B
- `rrr` - Do both rra and rrb simultaneously

---


## Technical Implementation

### Data Structures

Implemented a **Circular Doubly Linked List** to represent each stack because it allows ease of access to both head and tail, and makes all rotational operations extremely efficient.

```c
// Node structure
typedef struct s_node {
    int             value;
    struct s_node   *next;
    struct s_node   *prev;
} t_node;

// Stack structure
typedef struct s_stack {
    t_node  *head;
    int     size;
} t_stack;
```


---
### Sorting Algorithms

#### 1. Small Stack Optimization for 2-5 elements through Hardcoded Algorithm

- **2 elements:** Single swap `sa` if needed
- **3 elements:** All possible permutations and its moves are hardcoded.
- **4-5 elements:** Achieved by pushing smallest elements to Stack B until there are 3 elements remaining. Following which, Sort Three algorithm is used, then Push Back to A from B.


#### 2. Turk Sort for larger number of elements

- The core working of the Turk Sort, is achieved by moving the cheapest cost elements to Stack B, and then pushing them back to Stack A. The cheapest cost is calculated thoroughly in such a way that, when the element is to be pushed to Stack B, it will be placed in the sorted position to be at, with the least amount of moves needed from both stacks to achieve. 

- Initially, chunk methodology was used to identify cheapest cost element from the chunk, and push them. After testing with larger numbers, the efficiency wasn't as expected. Therefore, the chunk based turk sort was avoided and switched to a pure Turk Sort method.

- As steps here is the way, the efficient Turk Sort is being implemented in this project : 
  - Initially pushing first two elements to Stack B.
  - For every element in A, calculating the cost to push to the correct position in B.
  - Identifying and selecting the element with minimum total cost.
  - Applying Rotations in an optimized manner by rotaining both stacks at the same time when needed using `rr` and `rrr`.
  - When there are 3 elements remaining in Stack A, performing the hardcoded Sort_Three algorithm on Stack A. 
  - Pushing back all elements from stack B to A, by rotating A to the correct position.

---

### The Functions Utilized for Push_Swap

#### Circular List Management (`utils/circ_list/`)

- **`stack_init()`** - Allocates and initializes a new empty stack
- **`create_node(int value)`** - Allocates a new node with given value
- **`stack_push(t_stack *stack, int value)`** - Pushes value to front of stack
- **`stack_push_back(t_stack *stack, int value)`** - Pushes value to back of stack
- **`stack_pop(t_stack *stack)`** - Removes and returns head value, updates links
- **`stack_clear(t_stack **stack)`** - Frees all nodes and stack structure
- **`stack_find_node(t_stack *stack, int value)`** - Searches for value and returns that node
- **`stack_find_min(t_stack *stack)`** - Finds node with least value in the stack
- **`stack_find_max(t_stack *stack)`** - Finds node with largest value in the stack
- **`stack_node_distance(t_stack *stack, t_node *node)`** - Returns least distance to node from the head. If the closest path is backwards, the value returned will be negative.
- **`stack_node_is_forward(t_stack *stack, t_node *node)`** - Returns 1 if forward rotation is optimal, -1 if reverse, 0 if already at head
- **`stack_rotate_till_reached(t_stack *stack, char stack_id, t_node *node)`** - Rotates stack until node is at head for the specified stack

#### Input Validation (`utils/input_validator.c`)

- **`validate_and_store(t_stack *numList, int count, char **input)`** - Handles multiple arguments and space-separated strings in different combinations as well. Utilizes `ft_split()` to break space-separated values, and calls `process_splitted_str()` for each argument

- **`process_splitted_str(char **splitted_str, t_stack *numList)`** - Processes array of strings by validating each string is numeric, and calls `process_and_store_num()` for each valid number

- **`process_and_store_num(t_stack *numList, char *str)`** - Converts and stores the number using `ft_atoll()` for safe conversion with overflow checking. During this, duplicates are checked using  `stack_find_node()`

- **`free_splitted_str(char **splitted_str)`** - Frees split array

- **`error_exit(t_stack *stack_a, t_stack *stack_b)`** - Cleanup and exit with "Error\n"

#### Extended Library Functions (`utils/expanded_libft/`)

- **`ft_atoll(const char *str, int *error)`** - Converts string to long long with error handling
  - Checks for overflow/underflow
  - Validates the entire string is numeric
  - Sets error flag for invalid input

- **`ft_is_just_number(char *str)`** - Validates string contains only digits (with optional +/- prefix)

- **`ft_min(int a, int b)` / `ft_max(int a, int b)`** - Return min/max of two integers

- **`ft_abs(int num)`** - Returns absolute value

- **`ft_puterr_exit(void)`** - Prints "Error\n" to stderr and exits

#### Sorting Helpers (`utils/sort_algorithm/`)

- **`is_sorted_stack(t_stack *numList)`** - Checks if stack is already sorted

- **`find_spot_in_a(t_stack *a, int value_to_push)`** - Finds where value belongs in sorted Stack A

- **`find_spot_in_b(t_stack *b, int value_to_push)`** - Finds where value belongs in sorted Stack B

- **`rotate_and_move(t_stack *a, t_stack *b, t_node *node_to_push_from_a)`** - Optimized rotation for Turk algorithm
  - Checks if both stacks can rotate together (rr/rrr)
  - Falls back to individual rotations
  - Pushes element to B

- **`update_min_node(...)`** - Updates cheapest node tracker

- **`find_cheapest_node(t_stack *a, t_stack *b, int nodes_traversed)`** - Core of Turk algorithm
  - Iterates through all nodes in A
  - Calculates cost to push each to B
  - Returns node with minimum total cost

#### Operation Rules (`utils/rules/`)

All operations follow the same pattern:
1. Check for valid stack(s) and minimum size
2. Perform the linked list manipulation
3. Print operation name to stdout

- **`swap.c`** - `sa`, `sb`, `ss` implementations
- **`push.c`** - `pa`, `pb` implementations
- **`rotate.c`** - `ra`, `rb`, `rr` implementations
- **`rev_rotate.c`** - `rra`, `rrb`, `rrr` implementations

---

### Standard Library (`libft/`)

This project includes the 42 **libft** library which provides standard C library functions. These are standard implementations and not documented here. Key functions used:

- `ft_split()` - Split strings by delimiter
- `ft_putstr_fd()` - Write strings to file descriptors
- `ft_isdigit()` - Character checking
- Memory management: `malloc`, `free`
- String functions

---








## Recap: What You Need

Before running this project, ensure you have:

- **Compiler:** `cc` or `gcc` with C99 support
- **Arguments:** A list of integers (can be space-separated or multiple arguments)
- **Checker:** The provided `checker_OS` binary for verification

---

## Instructions

### Compilation

#### Step 1: Build the libft library

```bash
# Navigate to the libft directory
cd libft

# Build the library
make

# Return to root
cd ..
```

#### Step 2: Build push_swap

```bash
# Compile the project
make
```

**Why:** The Makefile compiles all source files from the various utility directories, links them with the libft static library, and produces the `push_swap` executable.

---

### Execution

#### Run with individual arguments

```bash
./push_swap 5 3 8 1 9
```

#### Run with space-separated arguments

```bash
./push_swap "5 3 8 1 9"
```

#### Verify with the checker

```bash
./push_swap 5 3 8 1 9 | ./checker_OS 5 3 8 1 9
```

**Success Criteria:**
- Checker outputs: `OK` (stack is sorted)
- Checker outputs: `KO` (stack is NOT sorted)
- Checker outputs: `Error` (invalid input)

---

## Testing & Verification

### Test with random numbers

```bash
# Generate random numbers and test
ARG=$(seq 1 100 | sort -R | head -n 5 | tr '\n' ' ')
./push_swap $ARG | ./checker_OS $ARG
```

### Count the number of operations

```bash
# Count moves for 100 random numbers
ARG=$(seq 1 100 | sort -R | head -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l
```

**Expected Performance:**
- 3 numbers: ≤ 3 moves
- 5 numbers: ≤ 12 moves
- 100 numbers: ~700 moves (max ~1500)
- 500 numbers: ~5500 moves (max ~11500)

### Edge Cases to Test

```bash
# Already sorted
./push_swap 1 2 3 4 5

# Reverse sorted
./push_swap 5 4 3 2 1

# Duplicates (should error)
./push_swap 1 2 2 3

# Non-numeric (should error)
./push_swap 1 a 3

# Integer overflow (should error)
./push_swap 2147483648

# Empty (should do nothing)
./push_swap
```


## Resources

### Documentation

- [Turk Algorithm Explanation](https://medium.com/@ayogun/push-swap-c1f10d4f4222) - Good breakdown of the algorithm
- [Push Swap Tutorial](https://www.youtube.com/watch?v=wRpg2iuRLSs) - Visual explanation

### Algorithm References

- [Doubly Linked List](https://en.wikipedia.org/wiki/Doubly_linked_list) - Data structure used
- [Circular Buffer](https://en.wikipedia.org/wiki/Circular_buffer) - Concept behind circular list
- [Sorting Algorithms](https://en.wikipedia.org/wiki/Sorting_algorithm) - General sorting concepts

### AI Usage

AI was used during development for:
- Code review and optimization suggestions
- Debugging complex pointer manipulation issues
- Explaining the Turk algorithm concept
- Generating test cases and edge case scenarios

The core algorithm implementation and data structure design were written manually based on understanding of the Turk sort approach.

---

## Why This Implementation?

**Circular doubly linked list** was chosen because:
- O(1) rotation (just move head pointer)
- O(1) access to both ends
- No need to traverse for tail operations
- Natural fit for the rotate/reverse-rotate operations

**Turk algorithm** was chosen because:
- Efficient for larger datasets (100-500 elements)
- Minimizes total moves by calculating costs
- Uses simultaneous rotations when possible (rr/rrr)
- Well-established solution for this project

**Input validation** includes:
- Integer overflow checking (uses long long for parsing)
- Duplicate detection
- Non-numeric character detection
- Empty argument handling
