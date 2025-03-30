#include <stdio.h>
#define WIZARD 0
#define KNIGHT 1
#define ARCHER 2

// ========================
struct Wizard {
    char name[16];
    unsigned int hp;
    int class;
    unsigned int magicPower;
};

struct Knight {
    char name[16];
    unsigned int hp;
    int class;
    unsigned short stamina;
};

struct Archer {
    char name[16];
    unsigned int hp;
    int class;
    unsigned char arrow;
};

// How to configurate the struct for common properties and class specific properties?
/**
 * Case 1. Use Struct
 * - Problem: wasted memory space, one character will use one of the class specific properties
 * - however, all three properties are saved, taking up 7 bytes of memory
 */ 
struct Character {
    // Common properties 
    int class;
    char name[16];
    unsigned int hp;

    // Class specific properties
    unsigned int magicPower;   // 4 bytes
    unsigned short stamina;    // 2 bytes
    unsigned char arrow;       // 1 byte
};

/**
 * Case 2. Use Union
 * - Many properties are able to share same memory space (or, one memory space has various name/data types)
 * - Variables have same memory address
 * - When one variable value changes, all other variables are affected
 */
union status {
    unsigned int magicPower;   // 4 bytes
    unsigned short stamina;    // 2 bytes
    unsigned char arrow;       // 1 byte
};
/** 
 * Memory allocation: (one block is one byte)
 * | magicPower/stamina/arrow | magicPower/stamina | magicPower | magicPower |
 */

/**
 * Case 3. Use Union in Struct
 */
struct Character_2 {
    // Common properties 
    int class;
    char name[16];
    unsigned int hp;

    // Class specific properties
    // union status stat;
    union {
        unsigned int magicPower;   // 4 bytes
        unsigned short stamina;    // 2 bytes
        unsigned char arrow;       // 1 byte
    };
};
// ========================

void printMember(union status* stat) {
    // combine three properties into one printf:
    printf("Magic Power: %d, Stamina: %d, Arrow: %d\n", stat->magicPower, stat->stamina, stat->arrow);
}

void printCharacter(struct Character_2* character) {
    switch (character->class) {
        case WIZARD:
            printf("Wizard: %s, HP: %d, Magic Power: %d\n", character->name, character->hp, character->magicPower);
            break;
        case KNIGHT:
            printf("Knight: %s, HP: %d, Stamina: %d\n", character->name, character->hp, character->stamina);
            break;
        case ARCHER:    
            printf("Archer: %s, HP: %d, Arrow: %d\n", character->name, character->hp, character->arrow);
            break;
        default:
            printf("Invalid class\n");
            break;
    }
}

int main(void) {

    // union status st = { 100, 50, 'A' };  // Error: cannot initialize union with multiple values because they share memory space
    union status st;
    st.magicPower = 100;
    st.stamina = 50;
    st.arrow = 'A';

    union status stat[3] = { 5000, 1000, 24 };      // union array
    printf("Size of union = %d bytes\n", sizeof(union status)); // 4 bytes

    for (int i = 0; i < 3; i++) {
        printf("[%d] ", i);
        printMember(&stat[i]);
    }
    // [0] Magic Power: 5000, Stamina: 5000, Arrow: 136
    // [1] Magic Power: 1000, Stamina: 1000, Arrow: 232
    // [2] Magic Power: 24, Stamina: 24, Arrow: 24

    stat[0].arrow = 'B';
    printMember(&stat[0]);
    // Magic Power: 4930, Stamina: 4930, Arrow: 66 
    // --> first byte is changed to 'B', so magicPower and stamina values are changed as well

    // FINAL IMPLEMENTATION AFTER CASE 3.
    struct Character_2 characters[3] = {
        { WIZARD, "Wizard", 100, 5000 },
        { KNIGHT, "Knight", 200, 1000 },
        { ARCHER, "Archer", 300, 24 }
    };

    for (int i = 0; i < 3; i++) {
        printCharacter(&characters[i]);
    }

    return 0;
} 