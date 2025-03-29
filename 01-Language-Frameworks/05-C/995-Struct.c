#include <stdio.h>
#define NUM_CARDS 3

struct Card {
    char name[10];  // 10 bytes
    int power;      // 4 bytes
};

typedef struct {
    char name[10];  // 10 bytes
    int power;      // 4 bytes
} Card_2;

int main(void) {

    struct Card cards[NUM_CARDS] = { 0 };   // initialize all elements to 0

    // Code to input the cards
    // for (int i = 0; i < NUM_CARDS; i++) {
    //     printf("Enter the name of the card: ");
    //     scanf("%s", cards[i].name);       
    //     printf("Enter the power of the card: ");
    //     scanf("%d", &cards[i].power);
    // }
    /** 
     * TIP: 
     * char array does not need &, because input is already a pointer
     * int needs & because it is a value  
     * */ 

    /**
     * TIP: 
     * Code below leads to error "identifier "Card" is undefined"
     * Card card1 = { "Card1", 10 };
     * 
     * To fix this,
     * (1) Use struct keyword when declaring the variable
     * (2) Use typedef to define the struct
     */ 

    // (1)
    struct Card card1 = { "Card1", 10 };
    struct Card card2 = { "Card2", 20 };
    struct Card card3 = { "Card3", 30 };

    // (2)
    Card_2 card4 = { "Card4", 40 };

    cards[0] = card1;
    cards[1] = card2;
    cards[2] = card3;

    int best = 0;
    for (int i = 1; i < NUM_CARDS; i++) {
        if (cards[i].power > cards[best].power) {
            best = i;
        }
    }

    printf("The best card is %s with a power of %d\n", cards[best].name, cards[best].power);

    int elementSize = sizeof(struct Card);

    printf("Size of struct Card: %d\n", elementSize);
    printf("Number of elements in cards: %d\n", sizeof(cards) / elementSize);
    /**
     * TIP:
     * Card size is 10 bytes + 4 bytes = 14 bytes, however elementSize prints 16 bytes.
     * A struct's size is determined by the largest data type in the struct.
     * In this case, the largest data type is int, which is 4 bytes.
     * Memory is allocated consecutively for each variable in the struct, 
     * so 10 + 4 = 14 bytes are used, however 2 bytes are placed in between as padding.
     * 
     * TIP:
     * CPU accesses memory by Word
     * - 32-bit system: 4 bytes
     * - 64-bit system: 8 bytes
     * 
     * TIP:
     * when struct is saved, member variables are placed in memory so memory is accessed less frequently
     * This is called "Data Structure Padding"
     * 
     * Ex (X - wrong implementation of padding)
     * ========================
     * c - char, i - int, p - padding
     * |c|c|c|c|c|c|c|c|
     * |c|c|i|i|i|i|p|p|
     * ========================
     * --> if Word was 4 bytes, CPU would access memory 2 times to access the int variable
     * --> 1: |c|c|i|i|, 2: |i|i|p|p|
     * 
     * 
     * Ex (O - correct implementation of padding)
     * ========================
     * c - char, i - int, p - padding
     * |c|c|c|c|c|c|c|c|
     * |c|c|p|p|i|i|i|i|
     * ========================
     * --> if Word was 4 bytes, CPU would access memory 1 times to access the int variable
     * --> 1: |i|i|i|i|
     */

    printf("Address of variable name: %p\n", &cards[0].name);
    printf("Address of variable power: %p\n", &cards[0].power);

    return 0;

}