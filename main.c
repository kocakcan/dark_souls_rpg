#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "character.h"
#include "class.h"
#include "constants.h"
#include "combat.h"
#include "input.h"

#define MAX_HP	100

int main(void) {
	srand(time(NULL));

	Character player;
	choose_class(&player);

	Character boss;
	init_character(&boss, "Manus, Father of the Abyss", MAX_HP + 50, 20, 0);

	printf("⚔️  %s vs. %s begins!\n", player.name, boss.name);

	while (is_alive(&player) && is_alive(&boss)) {
	    printf("\n--- BATTLE STATUS ---\n");
	    print_status(&player);
	    print_status(&boss);

	    // Apply status effects before player's turn
	    apply_status_effects(&player);
	    apply_status_effects(&boss);

	    // Player's turn
	    player_turn(&player, &boss);
	    if (!is_alive(&boss)) break;

	    // Apply again in case boss got burned mid-turn
	    apply_status_effects(&player);
	    apply_status_effects(&boss);

	    // Boss's turn
	    printf("\n👹 %s's turn...\n", boss.name);
	    attack(&boss, &player);
	}

	if (is_alive(&player))
		printf("\n🏆 Victory! %s has defeated %s!\n", player.name, boss.name);
    	else
		printf("\n💀 You Died. %s has fallen to %s...\n", player.name, boss.name);

    return 0;
}
