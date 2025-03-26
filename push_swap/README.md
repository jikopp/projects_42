# Push_swap

## Introduction

The `push_swap` project is a sorting algorithm implementation for the 42 curriculum. The goal is to sort a stack of numbers using a minimal number of operations while adhering to specific constraints. The sorting operations involve pushing and swapping elements between two stacks (`a` and `b`).

## How It Works

The program takes a list of integers as arguments and sorts them using a set of predefined operations:
- `sa`, `sb`, `ss` (Swap)
- `pa`, `pb` (Push)
- `ra`, `rb`, `rr` (Rotate)
- `rra`, `rrb`, `rrr` (Reverse Rotate)

The algorithm is optimized to sort numbers efficiently, especially for small input sizes, using a combination of sorting techniques such as:
- Simple sorting for three numbers.
- Pushing elements to a secondary stack (`b`) and moving them back optimally.
- Cost calculation to determine the best moves.

---

## Walkthrough of Functions

### Initialization and Error Handling
- `error_syntax(char *str)`: Checks if the given input string contains valid numbers.
- `duplicate_error(t_Node *root, int nbr)`: Ensures there are no duplicate numbers.
- `free_errors(t_Node **root)`: Frees memory and exits with an error message if invalid input is detected.
- `init_list_a(t_Node **a, char **av)`: Parses the input arguments and creates the linked list for stack `a`.
- `free_split_result(char **array)`: Frees memory allocated for split arguments.

### Sorting Logic
- `choose_sort(t_Node **a, t_Node **b)`: Determines the appropriate sorting algorithm based on input size.
- `sort_three(t_Node **root)`: Optimized sorting function for three numbers.
- `sort_list(t_Node **a, t_Node **b)`: General sorting function for larger lists.

### Node Preparation
- `prep_nodes_a(t_Node *a, t_Node *b)`: Prepares stack `a` nodes by assigning target nodes in `b`.
- `prep_nodes_b(t_Node *a, t_Node *b)`: Prepares stack `b` nodes by assigning target nodes in `a`.
- `index_and_median(t_Node *root)`: Assigns an index to each node and determines the median.
- `target_for_a(t_Node *a, t_Node *b)`: Finds the best target for each node in stack `a`.
- `target_for_b(t_Node *a, t_Node *b)`: Finds the best target for each node in stack `b`.

### Movement and Sorting Operations
- `move_a_to_b(t_Node **a, t_Node **b)`: Moves elements from `a` to `b` based on cost calculations.
- `move_b_to_a(t_Node **a, t_Node **b)`: Moves elements from `b` back to `a` optimally.
- `prep_for_push(t_Node **root, t_Node *top_node, char list_name)`: Prepares a node for pushing by rotating the stack.
- `min_on_top(t_Node **a)`: Ensures the smallest number is positioned at the top of `a`.

### Cost Calculation and Selection
- `check_fee(t_Node *a, t_Node *b)`: Computes the cost of moving each element.
- `set_lowest(t_Node *root)`: Determines the node with the lowest cost.
- `get_lowest(t_Node *root)`: Retrieves the node with the lowest cost.

### Stack Rotations and Swaps
- `rotate_both(t_Node **a, t_Node **b, t_Node *lowest_fee)`: Rotates both stacks simultaneously.
- `rev_rotate_both(t_Node **a, t_Node **b, t_Node *lowest_fee)`: Reverse rotates both stacks simultaneously.

### Commands
- **Swap**: `sa`, `sb`, `ss`
- **Push**: `pa`, `pb`
- **Rotate**: `ra`, `rb`, `rr`
- **Reverse Rotate**: `rra`, `rrb`, `rrr`

---

## How to Use

### Compilation
To compile the project, use:
```sh
make
```

### Execution
To run the program:
```sh
./push_swap <list of numbers>
```
Example:
```sh
./push_swap 4 3 2 1
```

### Error Handling
If invalid input is provided, the program prints `Error` and exits.

---

## Conclusion
The `push_swap` project is a challenging exercise in algorithmic optimization and linked list manipulation. By implementing a sorting algorithm with stack-based operations, it provides a deep understanding of algorithmic efficiency and problem-solving techniques.

