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
			player->spell_type = "Miracle";
			player->spell_uses = 2;
			break;
		case 2:
			init_character(player, "Sorcerer", 80, 10, 1);
			player->weapon = "Staff";
			player->spell = "Soul Arrow";
			player->spell_type = "Sorcery";
			player->spell_uses = 3;
			break;
		case 3:
			init_character(player, "Pyromancer", 90, 15, 2);
			player->weapon = "Axe";
			player->spell = "Fireball";
			player->spell_type = "Pyromancy";
			player->spell_uses = 2;
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
