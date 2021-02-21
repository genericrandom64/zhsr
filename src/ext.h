#ifndef EXT_H
#define EXT_H

// A series of extensions for c++ functionality.

namespace generic {

}

bool strMatch(char* s1, char* s2) {
	return strcmp(s1, s2);
}

template <class T>
struct dlnode { // Doubly linked node
	T value;
	dlnode* next = NULL;
	dlnode* prev = NULL;
};

template <class T>
struct list {
	dlnode<T>* first = NULL;
	dlnode<T>* last = NULL;
	int end = 0;
	// Add new item to start of list
	void pushb(T val) {
		dlnode<T>* add = new dlnode<T>;
		add->value = val;
		if (first == NULL) {
			first = add;
			last = add;
			return;
		}
		last->next = add;
		add->prev = last;
		last = add;
		end++;
		return;
	}
	// Add new item to end of list
	void pushf(T val) {
		dlnode<T>* add = new dlnode<T>;
		add->value = val;
		if (last == NULL) {
			first = add;
			last = add;
			return;
		}
		first->prev = add;
		add->next = first;
		first = add;
		end++;
		return;
	}
	void insert(T val, int idx) {
		
	}
	// Returns first item and removes it
	T popf() {
		if (first == NULL) { return NULL; }
		T val = first->value;
		if (first->next == NULL) {
			first = NULL;
			last = NULL;
			return val;
		}
		first = first->next;
		return val;
	}
	// Returns last item and removes it
	T popb() {
		if (last == NULL) { return NULL; }
		T val = last->value;
		if (last->prev == NULL) {
			first = NULL;
			last = NULL;
			return val;
		}
		last = last->prev;
		return val;
	}
	void remove(int idx) {
		
	}
	// Returns the first item
	T peekf() {
		if (first == NULL) { return NULL; }
		return first->value;
	}
	// Returns the last item
	T peekb() {
		if (last == NULL) { return NULL; }
		return last->value;
	}
	// Looks for first occurence of val and returns its index
	// If val is not found, returns -1
	int find(T val) {
		dlnode<T>* current = first;
		for (int idx = 0; current != NULL; idx++) {
			if (current->value == val) { return idx; }
			current = current->next;
		}
		return -1;
	}
	T get(int idx) {
		dlnode<T>* current;
		current = first;
		for (int i = 0; i < idx; i++) {
			if (current != NULL) current = current->next;
		}
		if (current == NULL) return NULL;
		return current->value;
	}
};

template <class T>
struct array {
	T* ptr = NULL;
	int end = -1;
	// Inserts value as last item in list
	// Returns index of inserted value
	int append(T value) {
		if (end < 0) {
			ptr = (T*) malloc(1 * sizeof(T));
		} else {
			ptr = (T*) realloc(ptr, (end + 2) * sizeof(T));
		}
		end++;
		*(ptr + end) = value;
		return end;
	}
	// Inserts value as first item in list, increases proceding items by one index
	// Returns index of inserted value
	int prepend(T value) {
		
		return 0;
	}
	// Inserts value at specified index
	// If offset is 0 or positive, value will be inserted after index
	// If offset is negative, value will be inserted before index
	// If index out of range, returns null
	int insert(T value, int idx, int ofs) {
		if (idx < 0 or idx > end) { return NULL; }
		return idx;
	}
	// Returns value at given index
	// If index out of bounds or list empty, returns null
	T get(int idx) {
		if (idx > end or end < 0) { return NULL; }
		return *(ptr+idx);
	}
	// Returns index of first occurence of given value
	// If not found, returns -1
	// If list empty, returns null
	int find(T value) {
		if (end < 0) { return NULL; }
		for (int idx = 0; idx < end + 1; idx++) {
			printf("idx: %i\n",idx);
			if (*(ptr + idx) == value) { return idx; }
		}
		return -1;
	}
};
#endif