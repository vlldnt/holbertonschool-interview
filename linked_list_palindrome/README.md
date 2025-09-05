
# Linked List Palindrome

This project is part of the Holberton School Interview Preparation curriculum. The goal is to implement a function in C that checks if a singly linked list is a palindrome.

## 📚 Problem Description

- Given a singly linked list, determine if the sequence of values is the same forwards and backwards.
- An empty list is considered a palindrome.

## 🚀 Usage

- **Prototype:** `int is_palindrome(listint_t **head);`
- Returns `1` if the list is a palindrome, `0` otherwise.

## 🛠️ Requirements

- C, Betty style
- No global variables
- No more than 5 functions per file
- All prototypes in `lists.h` (with include guards)
- Compiled with `gcc -Wall -Werror -Wextra -pedantic`

## 📝 Example

```c
listint_t *head = NULL;
add_nodeint_end(&head, 1);
add_nodeint_end(&head, 17);
add_nodeint_end(&head, 972);
add_nodeint_end(&head, 50);
add_nodeint_end(&head, 98);
add_nodeint_end(&head, 98);
add_nodeint_end(&head, 50);
add_nodeint_end(&head, 972);
add_nodeint_end(&head, 17);
add_nodeint_end(&head, 1);

if (is_palindrome(&head) == 1)
    printf("Linked list is a palindrome\\n");
else
    printf("Linked list is not a palindrome\\n");