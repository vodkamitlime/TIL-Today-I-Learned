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

/** 
 * TIP: Bit field
 * - Bit field allows assigning the size of a member variable in bits
 * - !! ONLY WORKS WITH INT or UNSIGNED INT !! 
 * - Can assign bit padding for variable alignment (purpose: when accessing variable, minimizes memory access by CPU)
 * - If bit padding is 0, it fills padding bit until next word boundary 
 * - If value takes up more bits than assigned, it will overflow
 *    - Ex) value 10 is assigned to field of 3 bits, overflow will occur
 *    -     2^3-1 = 7, 10 = 1010 (binary)
 *    -     1010 -> 010 (overflow) -> value 2 is stored
 * - Cannot use address operator (&) with bit field variable, because it is not assured that variable will start at the beginning of byte
 */
struct BitField {
    unsigned int cost : 3;  // ~ 8 values (0 ~ 7)
    unsigned int : 1;       // 1 bit padding
    unsigned int atk : 10;  // ~2^10 - 1
    unsigned int : 0;       // bit padding until next word boundary
    unsigned int hp : 10;   // ~2^10 - 1
};
/**
 * ========================
 * one block is one bit
 * | cost | cost | cost | p   | atk | atk | atk | atk | 
 * | atk  | atk  | atk  | atk | atk | atk | p   | p   |
 * | p    | p    | p    | p   | p   | p   | p   | p   |
 * | p    | p    | p    | p   | p   | p   | p   | p   | --> end of word boundary (in 32-bit system, Word is 4 bytes)
 * | hp   | hp   | hp   | hp  | hp  | hp  | hp  | hp  |
 * | hp   | hp   |      |     |     |     |     |     |
 * ========================
 * 
 */


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
     * one block is one byte
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
     * one block is one byte
     * c - char, i - int, p - padding
     * |c|c|c|c|c|c|c|c|
     * |c|c|p|p|i|i|i|i|
     * ========================
     * --> if Word was 4 bytes, CPU would access memory 1 times to access the int variable
     * --> 1: |i|i|i|i|
     */

    printf("Address of variable name: %p\n", &cards[0].name);
    printf("Address of variable power: %p\n", &cards[0].power);

    // Bit Field 
    struct BitField bf = { 10, 10, 10 };
    printf("Cost: %d\n", bf.cost);  // Prints 2 due to bit overflow
    printf("Atk: %d\n", bf.atk);
    printf("HP: %d\n", bf.hp);

    return 0;

}