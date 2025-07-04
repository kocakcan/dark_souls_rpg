#include <stdio.h>
#include "input.h"
#include "combat.h"

void player_turn(Character *player, Character *boss) {
	printf("\nYour turn:\n");
	printf("1. Attack\n");
	printf("2. Roll\n");
	printf("3. Drink Estus (%d left)\n", player->estus);
	printf("> ");

	int choice;
	scanf("%d", &choice);

	switch (choice) {
		case 1: attack(player, boss); 	break;
		case 2: roll(player); 		break;
		case 3: drink_estus(player); 	break;
		default: printf("Invalid choice. You hesitate...\n");
	}
}
