#include <stdio.h>
#include <string.h>
#include "class.h"

void choose_class(Character *player) {
	printf("Choose your class:\n");
	printf("1. Knight\n");
	printf("2. Sorcerer\n");
	printf("3. Pyromancer\n");
	printf("> ");

	int choice;
	scanf("%d", &choice);

	switch (choice) {
		case 1:
			init_character(player, "Knight", 120, 20, 2);
			player->weapon = "Greatsword";
			player->spell = "None";
			break;
		case 2:
			init_character(player, "Sorcerer", 80, 10, 1);
			player->weapon = "Staff";
			player->spell = "Soul Arrow";
			break;
		case 3:
			init_character(player, "Pyromancer", 90, 15, 2);
			player->weapon = "Axe";
			player->spell = "Fireball";
			break;
		default:
			printf("Invalid choice. Defaulting to Knight.\n");
			init_character(player, "Knight", 120, 20, 2);
			player->weapon = "Greatsword";
			player->spell = "None";
			break;
	}

	printf("You chose: %s\n", player->name);
	printf("Weapon: %s | Spell: %s\n", player->weapon, player->spell);
}
