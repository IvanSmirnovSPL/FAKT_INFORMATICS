#include <iostream>

#define CAPACITY 50000 // Size of the Hash Table

unsigned long hash_function(std::string str) {
    unsigned long i = 0;
    for (int j = 0; str[j]; j++)
        i += str[j];
    return i % CAPACITY;
}

struct Ht_item {
    std::string key;
    std::string value;
};

struct HashTable {
    // Contains an array of pointers
    // to items
    Ht_item** items;
    int size;
    int count;
};

Ht_item* create_item(std::string key, std::string value) {
    // Creates a pointer to a new hash table item
    Ht_item* item =new Ht_item;
    item->key = key;
    item->value = value;
    return item;
}

HashTable* create_table(int size) {
    // Creates a new HashTable
    HashTable* table = new HashTable;
    table->size = size;
    table->count = 0;
    table->items = new Ht_item*[size];
    for (int i = 0; i < table->size; i++)
        table->items[i] = NULL;
    return table;
}

void free_item(Ht_item* item) {
    free(item);
}

void free_table(HashTable* table) {
    // Frees the table
    for (int i = 0; i < table->size; i++) {
        Ht_item* item = table->items[i];
        if (item != NULL)
            free_item(item);
    }

    free(table->items);
    free(table);
}

void ht_insert(HashTable* table, std::string key, std::string value) {
    // Create the item
    Ht_item* item = create_item(key, value);

    int index = hash_function(key);
    Ht_item* current_item = table->items[index];

    if (current_item == NULL) {
        // Key does not exist.
        if (table->count == table->size) {
            // Hash Table Full
            printf("Insert Error: Hash Table is full\n");
            return;
        }


        // Insert directly
        table->items[index] = item;
        table->count++;
    }

    else {
        // Scenario 1: We only need to update value
        if (current_item->key == key) {
            table->items[index]->value = value;
            return;
        }

        else {
            // Scenario 2: Collision
             // We will handle case this a bit later
            printf("Insert Error: Collision\n");
            //handle_collision(table, item);
            return;
        }
    }
}

std::string* ht_search(HashTable* table, std::string key) {
    // Searches the key in the hashtable
    // and returns NULL if it doesn't exist
    int index = hash_function(key);
    Ht_item* item = table->items[index];

    // Ensure that we move to a non NULL item
    if (item != NULL) {
        if (item->key == key)
            auto tmp = item->value;
            return &item->value;
    }
    return NULL;
}

void print_search(HashTable* table, std::string key) {
    std::string* val;
    if ((val = ht_search(table, key)) == NULL) {
        std::cout << "Key: " << key << " does not exist" << std::endl;
        return;
    }
    else {
        std::cout << "Key: " << key << ", Val: " << *val << std::endl;;
    }
}

void print_table(HashTable* table) {
    std::cout << "\nHash Table\n-------------------\n" << std::endl;
    for (int i = 0; i < table->size; i++) {
        if (table->items[i]) {
            std::cout << "Index: " << i << ", Key: " << table->items[i]->key << ", Val: " << table->items[i]->value << std::endl;
        }
    }
    std::cout << "\n-------------------\n" << std::endl;
}

int main()
{
    HashTable* ht = create_table(CAPACITY);
    ht_insert(ht, "1", "First address");
    ht_insert(ht, "2", "Second address");
    print_search(ht, "1");
    print_search(ht, "2");
    print_search(ht, "3");
    print_table(ht);
    free_table(ht);
    return 0;
}

// https://www.8host.com/blog/xesh-tablica-v-c-c-polnaya-realizaciya/