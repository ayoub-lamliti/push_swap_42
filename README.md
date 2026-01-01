*This project has been created as part of the 42 curriculum by alamliti.*

# 🖥️ Push Swap

## Description

The Push Swap project is a comprehensive algorithm challenge at 42. Its primary goal is to sort data on a stack using a limited set of instructions and the smallest number of moves possible.

This repository features the Checker program (the bonus part of the project). The Checker takes a list of integers as arguments, reads sorting instructions from the standard input (stdin), and executes them. Its main purpose is to verify whether the provided instructions successfully sort the stack and ensure stack B is empty.

## Instructions

### Compilation

To compile the checker program, run the following command in the root of the repository:

```bash
make && make bonus
```
### Execution

```bash
./push_swap 4 67 3 87 23
./push_swap 4 67 3 87 23 | wc -l
```
You can run the checker manually by passing a list of integers:

```bash
./checker 4 67 3 87 23
```
The program will wait for input. You can type instructions (like sa, pb, rra) followed by Enter. To finish input and check the result, press CTRL+D (EOF).

### Usage with Push_swap

The standard way to use the checker is to verify the output of your push_swap program using a pipe:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG 
# or if u use fish 
set ARG "4 67 3 87 23" ; ./push_swap $ARG | ./checker $ARG
```

## Output

* ok: The stack is correctly sorted and stack B is empty.
* ko: The stack is not sorted.
* Error: If there are invalid arguments (duplicates, non-integers) or unknown instructions.

## Resources

### References
* Sorting Algorithms: GeeksforGeeks - Sorting Algorithms

* Stack Data Structure: Tutorialspoint - Stack


### AI Usage
As per the project requirements, Artificial Intelligence tools (specifically Gemini/ChatGPT) were used in the development of this project for the following tasks:

* Concept Clarification: To understand the logic behind stack manipulation and parsing input arguments.
* Debugging: Assisted in identifying segmentation faults and logic errors in the instruction handling functions.
* Documentation: Generated the structure and content of this README.md file to ensure compliance with the 42 submission guidelines.
