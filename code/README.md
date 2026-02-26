***This project has been created as part of the 42 curriculum by ssujaude.***

## Description

Push_swap is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using two stacks (Stack A and Stack B) with a limited set of operations. The challenge lies in finding the most efficient way to sort with the minimum number of moves.

The project implements the **Turk Algorithm** (also known as the "Turk Sort"), which is a clever approach that calculates the cost of moving each element and chooses the cheapest path. For smaller stacks (2-5 elements), specialized hardcoded algorithms are used for optimal performance.

### Key Features

- **Circular doubly linked list** implementation for efficient rotation operations
- **Cost-based sorting** using the Turk algorithm for stacks > 5 elements
- **Input validation** with support for space-separated arguments
- **Error handling** for invalid inputs, duplicates, and integer overflow

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

---

## Technical Implementation

### Data Structures

The project uses a **circular doubly linked list** to represent each stack:

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

**Why circular?** This design allows O(1) access to both the head and tail, making rotation operations (ra, rb, rra, rrb) extremely efficient.

---

### Operations

All operations print their name to stdout:

#### Swap Operations
- `sa` - Swap top two elements of Stack A
- `sb` - Swap top two elements of Stack B
- `ss` - Do both sa and sb simultaneously

#### Push Operations
- `pa` - Push top element from Stack B to Stack A
- `pb` - Push top element from Stack A to Stack B

#### Rotate Operations (upwards)
- `ra` - Rotate Stack A (first becomes last)
- `rb` - Rotate Stack B
- `rr` - Do both ra and rb simultaneously

#### Reverse Rotate Operations (downwards)
- `rra` - Reverse rotate Stack A (last becomes first)
- `rrb` - Reverse rotate Stack B
- `rrr` - Do both rra and rrb simultaneously

---

### Sorting Algorithms

#### 1. Small Stack Optimization (2-5 elements)

For stacks with ≤5 elements, hardcoded logic is used:

- **2 elements:** Single swap if needed
- **3 elements:** 5 possible configurations handled directly
- **4-5 elements:** Push minimums to Stack B, sort remainder, push back

**File:** `utils/sort_algorithm/sort_three.c`, `sort_five.c`

#### 2. Turk Algorithm (5+ elements)

The Turk algorithm works by:

1. **Initial phase:** Push first two elements to Stack B
2. **Push to B:** For each element in A, calculate the cost to push to the correct position in B
3. **Find cheapest:** Select the element with minimum total cost
4. **Optimize rotations:** When both stacks need rotation in the same direction, use `rr` or `rrr` to do both at once
5. **Final phase:** Push all elements back to A, rotating A to the correct position for each

**Key Insight:** The algorithm calculates `stack_node_distance()` for each element, which returns negative values for reverse rotation (when it's faster to go backwards).

**Files:** `utils/sort_algorithm/turk_sort.c`, `turk_sort_support.c`

---

### Utility Functions

#### Circular List Management (`utils/circ_list/`)

- **`stack_init()`** - Allocates and initializes a new empty stack
- **`create_node(int value)`** - Allocates a new node with given value
- **`stack_push(t_stack *stack, int value)`** - Pushes value to front of stack
- **`stack_push_back(t_stack *stack, int value)`** - Pushes value to back of stack
- **`stack_pop(t_stack *stack)`** - Removes and returns head value, updates links
- **`stack_clear(t_stack **stack)`** - Frees all nodes and stack structure
- **`stack_find_node(t_stack *stack, int value)`** - Searches for value (used for duplicates check)
- **`stack_find_min/max(t_stack *stack)`** - Finds min/max nodes
- **`stack_node_distance(t_stack *stack, t_node *node)`** - Returns distance to node (negative for reverse direction)
- **`stack_node_is_forward(t_stack *stack, t_node *node)`** - Returns 1 if forward rotation is optimal, -1 if reverse, 0 if already at head
- **`stack_rotate_till_reached(t_stack *stack, char stack_id, t_node *node)`** - Rotates stack until node is at head

#### Input Validation (`utils/input_validator.c`)

- **`validate_and_store(t_stack *numList, int count, char **input)`** - Main entry for parsing arguments
  - Handles multiple arguments and space-separated strings
  - Uses `ft_split()` to break space-separated values
  - Calls `process_splitted_str()` for each argument

- **`process_splitted_str(char **splitted_str, t_stack *numList)`** - Processes array of strings
  - Validates each string is numeric with `ft_is_just_number()`
  - Calls `process_and_store_num()` for each valid number

- **`process_and_store_num(t_stack *numList, char *str)`** - Converts and stores single number
  - Uses `ft_atoll()` for safe conversion with overflow checking
  - Checks for duplicates with `stack_find_node()`
  - Validates range within INT_MIN/INT_MAX

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
