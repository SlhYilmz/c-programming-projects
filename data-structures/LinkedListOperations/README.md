# Basic Linked List Operations
This repo includes basic operations done on the linked lists.

### Why did the function parameters use double pointers?
In C, when we pass a variable to a function, it is passed by value, which means a copy of the variable is made and any modifications made within the function will not affect the original variable. However, if we want to modify the original variable (in this case, the head pointer of the linked list), we need to pass a pointer to the variable.

Since we want to modify the head pointer in the add_element_to_front, add_element_to_back, and add_element_to_index functions (i.e., we want to change what the head pointer points to), we need to pass a pointer to the head pointer. This way, any changes made to the pointer itself (e.g., changing its value to point to a new node) will be reflected in the calling function.

By using a double pointer (Node** head), we can access and modify the original head pointer from within the function.

The head pointer is the starting point and keeps track of the first node in the list. By using a double pointer to the head pointer in the linked list functions, we can modify the head pointer itself. For example, when adding or removing elements, we may need to update the head pointer to reflect the changes. Using a double pointer allows us to modify the head pointer directly, ensuring that the changes persist outside the function.

### Can we rewrite the functions, so that it uses 1 pointer?
Certainly, we can do that. However, we must change the function signature from **void** to **Node \*** so that we can use the Nodes in the main function. This causes the ability to decrease when modifying the original pointer to the node, since we must always call the original pointer from the main.
