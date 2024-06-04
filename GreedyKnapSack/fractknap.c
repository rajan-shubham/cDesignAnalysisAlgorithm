#include <stdio.h>
#include <stdlib.h>

struct Item {
    int profit;
    int weight;
    double ratio; 
};

int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    return (item2->ratio - item1->ratio) > 0 ? 1 : -1;
}

double maxProfit(int capacity, struct Item items[], int n) {

    qsort(items, n, sizeof(items[0]), compare);

    double totalProfit = 0.0; 


    for (int i = 0; i < n; i++) {

        if (capacity - items[i].weight >= 0) {
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        } else { 
            double fraction = (double)capacity / items[i].weight;
            totalProfit += fraction * items[i].profit;
            break; 
        }
    }

    return totalProfit;
}

int main() {
    int numItems, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    struct Item items[numItems];
    printf("Enter the profits and weights of each item:\n");
    for (int i = 0; i < numItems; i++) {
        scanf("%d %d", &items[i].profit, &items[i].weight);
        items[i].ratio = (double)items[i].profit / items[i].weight; 
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);

    double max = maxProfit(capacity, items, numItems);
    printf("Maximum profit: %.2f\n", max);

    return 0;
}

/*
./a.out
Enter the number of items: 3
Enter the profits and weights of each item:
25 18
24 15
15 10
Enter the capacity of knapsack: 20
Maximum profit: 31.50
*/

/*
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int value;
    int weight;
    double ratio; // Value-to-weight ratio
};

// Comparison function to sort items by ratio in non-decreasing order
int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    return (item2->ratio - item1->ratio) > 0 ? 1 : -1;
}

// Function to compute maximum value using fractional knapsack
double fractionalKnapSack(int W, struct Item items[], int n) {
    // Sort items based on their value-to-weight ratio
    qsort(items, n, sizeof(items[0]), compare);

    double totalValue = 0.0; // Total value in knapsack

    // Fill the knapsack with items as much as possible
    for (int i = 0; i < n; i++) {
        // If adding the entire item exceeds knapsack capacity
        if (W - items[i].weight >= 0) {
            totalValue += items[i].value;
            W -= items[i].weight;
        } else { // Take fraction of item
            double fraction = (double)W / items[i].weight;
            totalValue += fraction * items[i].value;
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    printf("Enter the profits and weights of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (double)items[i].value / items[i].weight; // Calculate ratio
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &W);

    double maxValue = fractionalKnapSack(W, items, n);
    printf("Maximum value: %.2f\n", maxValue);

    return 0;
}
*/