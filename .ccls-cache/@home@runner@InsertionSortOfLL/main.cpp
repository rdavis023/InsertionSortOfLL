void insertionSort() {
    // If the list is empty or has only one element, it is already sorted.
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node *sorted = nullptr; // Start with an empty sorted list

    Node *current = head; // Process unsorted list
    while (current != nullptr) {
        Node *next = current->next; // Remember the next item

        // Find the correct position in the sorted list for the current node
        // and insert the current node there
        if (sorted == nullptr || sorted->value >= current->value) {
            // Insert at the beginning of the sorted list (or when it's empty)
            current->next = sorted;
            sorted = current;
        } else {
            // Search for the node after which current node should be inserted
            Node *s = sorted;
            while (s->next != nullptr && s->next->value < current->value) {
                s = s->next;
            }
            // Insert after the found node
            current->next = s->next;
            s->next = current;
        }

        current = next; // Move to the next element in the unsorted list
    }

    // Set the head to the beginning of the sorted list
    head = sorted;

    // Adjust the tail pointer
    Node *temp = head;
    while (temp != nullptr && temp->next != nullptr) {
        temp = temp->next;
    }
    tail = temp;
}
