#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "combat.h"

#define ESTUS_HEAL	30
#define ROLL_CHANCE	50
#define CRIT_CHANCE	20

int random_percent(void) {
	return rand() % 100;
}

void attack(Character *attacker, Character *defender) {
    if (defender->rolled) {
        printf("🌀 %s dodged the attack!\n", defender->name);
        defender->rolled = 0;
        return;
    }

    int damage = attacker->max_damage;

    // 🔧 Weapon-specific logic
    if (strcmp(attacker->weapon, "Greatsword") == 0) {
        damage += 5;
        printf("💥 %s slams with a Greatsword!\n", attacker->name);
    } else if (strcmp(attacker->weapon, "Axe") == 0) {
        int bonus = rand() % 6;
        damage += bonus;
        printf("🪓 %s swings the Axe wildly! (+%d)\n", attacker->name, bonus);
    } else if (strcmp(attacker->weapon, "Staff") == 0) {
        damage -= 5;
        printf("📏 Weak melee poke with the Staff!\n");
    }

    // 💪 Strength scaling (10% of STR as bonus)
    int str_bonus = attacker->str / 10;
    damage += str_bonus;

    if (str_bonus > 0)
        printf("💪 Strength scaling bonus: +%d\n", str_bonus);

    printf("🗡️  %s attacks %s for %d damage!\n", attacker->name, defender->name, damage);

    defender->hp -= damage;
    if (defender->hp < 0) defender->hp = 0;
}


void drink_estus(Character *c) {
	if (c->estus > 0) {
		c->hp += ESTUS_HEAL;
		if (c->hp > MAX_HP) c->hp = MAX_HP;
		c->estus--;
		printf("🧪 %s drinks Estus and restores %d HP!\n", c->name, ESTUS_HEAL);
    	} else {
		printf("❌ No Estus left!\n");
	}
}

void roll(Character *c) {
	if (random_percent() < ROLL_CHANCE) {
		printf("🌀 %s performs a perfect roll and will dodge the next attack!\n", c->name);
		c->rolled = 1;
	} else {
		printf("💢 %s tries to roll but stumbles!\n", c->name);
		c->rolled = 0;
	}
}

void cast_spell(Character *caster, Character *target) {
    if (caster->spell_uses <= 0) {
        printf("❌ No spell uses left!\n");
        return;
    }

    if (!caster->spell) {
        printf("🌀 No spell equipped.\n");
        return;
    }

    if (strcmp(caster->spell, "Soul Arrow") == 0) {
        int base = 25 + rand() % 10;
        int scaling = caster->intel / 5;
        int damage = base + scaling;

        printf("✨ %s casts Soul Arrow! %s takes %d magic damage!\n",
               caster->name, target->name, damage);

        target->hp -= damage;
        if (target->hp < 0) target->hp = 0;
    }

    else if (strcmp(caster->spell, "Fireball") == 0) {
        int base = 20 + rand() % 10;
        int scaling = caster->intel / 5;
        int damage = base + scaling;

        printf("🔥 %s casts Fireball! %s takes %d fire damage and starts burning!\n",
               caster->name, target->name, damage);

        target->hp -= damage;
        if (target->hp < 0) target->hp = 0;

        target->burning = 3; // Apply burn for 3 turns
    }

    else if (strcmp(caster->spell, "Heal") == 0) {
        int base = 30;
        int scaling = caster->fth / 2;
        int heal = base + scaling;

        printf("✨ %s casts Heal and restores %d HP!\n", caster->name, heal);

        caster->hp += heal;
        if (caster->hp > MAX_HP) caster->hp = MAX_HP;
    }

    else {
        printf("❌ Unknown spell: %s\n", caster->spell);
        return;
    }

    caster->spell_uses--;
}


void apply_status_effects(Character *c) {
	if (c->burning > 0) {
		int burn_dmg = 5 + rand() % + 5;
		printf("🔥 %s is burning and takes %d fire damage!\n", c->name, burn_dmg);
		c->hp -= burn_dmg;
		c->burning--;
		if (c->hp < 0) c->hp = 0;
	}
}
