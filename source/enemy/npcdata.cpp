/*=========================================================================

	npcdata.cpp

	Author:		CRB
	Created:
	Project:	Spongebob
	Purpose:

	Copyright (c) 2000 Climax Development Ltd

===========================================================================*/

#ifndef __ENEMY_NPC_H__
#include "enemy\npc.h"
#endif

#ifndef	__PLAYER_PLAYER_H__
#include "player\player.h"
#endif


CNpc::NPC_DATA CNpc::m_data[NPC_UNIT_TYPE_MAX] =
{
	{	// NPC_SANDY_CHEEKS
		NPC_INIT_DEFAULT,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_STATIC,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		true,
		3,
		128,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_GARY
		NPC_INIT_DEFAULT,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_GARY,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		2048,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_FALLING_ITEM
		NPC_INIT_FALLING_ITEM,
		NPC_SENSOR_FALLING_ITEM_USER_CLOSE,
		NPC_MOVEMENT_STATIC,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_FALLING_ITEM_FALL,
		NPC_TIMER_NONE,
		false,
		8,
		128,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_FISH_HOOK
		NPC_INIT_FISH_HOOK,
		NPC_SENSOR_FISH_HOOK_USER_CLOSE,
		NPC_MOVEMENT_STATIC,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_FISH_HOOK_RISE,
		NPC_TIMER_NONE,
		false,
		3,
		128,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_DUST_DEVIL
		NPC_INIT_RETURNING_HAZARD,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_RETURNING_HAZARD,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		2048,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_PENDULUM
		NPC_INIT_PENDULUM,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_PENDULUM,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		2048,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_FIREBALL
		NPC_INIT_FIREBALL,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_FIREBALL,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		40,
		2048,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_SAW_BLADE
		NPC_INIT_RETURNING_HAZARD,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_RETURNING_HAZARD,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		2048,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_SMALL_JELLYFISH_1
		NPC_INIT_DEFAULT,
		NPC_SENSOR_JELLYFISH_USER_CLOSE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_MOVEMENT_MODIFIER_JELLYFISH,
		NPC_CLOSE_JELLYFISH_EVADE,
		NPC_TIMER_NONE,
		false,
		3,
		128,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_SMALL_JELLYFISH_2
		NPC_INIT_DEFAULT,
		NPC_SENSOR_JELLYFISH_USER_CLOSE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_MOVEMENT_MODIFIER_JELLYFISH,
		NPC_CLOSE_JELLYFISH_EVADE,
		NPC_TIMER_NONE,
		false,
		3,
		128,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_LARGE_JELLYFISH
		NPC_INIT_DEFAULT,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		128,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_ANEMONE_1
		NPC_INIT_DEFAULT,
		NPC_SENSOR_ANEMONE_USER_CLOSE,
		NPC_MOVEMENT_STATIC,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_ANEMONE_1_ATTACK,
		NPC_TIMER_NONE,
		false,
		0,
		128,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_ANEMONE_2
		NPC_INIT_DEFAULT,
		NPC_SENSOR_ANEMONE_USER_CLOSE,
		NPC_MOVEMENT_STATIC,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_ANEMONE_2_ATTACK,
		NPC_TIMER_NONE,
		false,
		0,
		128,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_ANEMONE_3
		NPC_INIT_DEFAULT,
		NPC_SENSOR_ANEMONE_USER_CLOSE,
		NPC_MOVEMENT_STATIC,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_ANEMONE_3_ATTACK,
		NPC_TIMER_NONE,
		false,
		0,
		128,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_SKELETAL_FISH
		NPC_INIT_DEFAULT,
		NPC_SENSOR_GENERIC_USER_VISIBLE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_SKELETAL_FISH_ATTACK,
		NPC_TIMER_NONE,
		false,
		3,
		2048,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_CLAM
		NPC_INIT_DEFAULT,
		NPC_SENSOR_CLAM_USER_CLOSE,
		NPC_MOVEMENT_STATIC,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_CLAM_ATTACK,
		NPC_TIMER_NONE,
		0,
		128,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_SQUID_DART
		NPC_INIT_DEFAULT,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		5,
		256,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_FISH_FOLK
		NPC_INIT_FISH_FOLK,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_MOVEMENT_MODIFIER_FISH_FOLK,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		2,
		2048,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_PRICKLY_BUG
		NPC_INIT_DEFAULT,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		1,
		128,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_SEA_SNAKE_1
		NPC_INIT_DEFAULT,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		256,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_SEA_SNAKE_2
		NPC_INIT_DEFAULT,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		256,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_PUFFA_FISH
		NPC_INIT_DEFAULT,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		2,
		128,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_ANGLER_FISH
		NPC_INIT_DEFAULT,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		1,
		128,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_HERMIT_CRAB
		NPC_INIT_DEFAULT,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		2,
		128,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_MINE
		NPC_INIT_DEFAULT,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_STATIC,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		0,
		128,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_BOOGER_MONSTER
		NPC_INIT_DEFAULT,
		NPC_SENSOR_BOOGER_MONSTER_USER_CLOSE,
		NPC_MOVEMENT_STATIC,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_BOOGER_MONSTER_ATTACK,
		NPC_TIMER_NONE,
		false,
		0,
		128,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_SPIDER_CRAB
		NPC_INIT_DEFAULT,
		NPC_SENSOR_SPIDER_CRAB_USER_CLOSE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_SPIDER_CRAB_ATTACK,
		NPC_TIMER_NONE,
		false,
		3,
		2048,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_EYEBALL
		NPC_INIT_DEFAULT,
		NPC_SENSOR_EYEBALL_USER_CLOSE,
		NPC_MOVEMENT_STATIC,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_EYEBALL_ATTACK,
		NPC_TIMER_NONE,
		false,
		0,
		128,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_BABY_OCTOPUS
		NPC_INIT_DEFAULT,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_MOVEMENT_MODIFIER_OCTOPUS,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		2,
		512,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_ZOMBIE_FISH_FOLK
		NPC_INIT_FISH_FOLK,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_MOVEMENT_MODIFIER_FISH_FOLK,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		2,
		2048,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_NINJA_STARFISH
		NPC_INIT_DEFAULT,
		NPC_SENSOR_NINJA_STARFISH_USER_CLOSE,
		NPC_MOVEMENT_STATIC,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_GENERIC_USER_SEEK,
		NPC_TIMER_NONE,
		false,
		3,
		64,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_GHOST
		NPC_INIT_DEFAULT,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		2,
		128,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_GHOST_PIRATE
		NPC_INIT_GHOST_PIRATE,
		NPC_SENSOR_GHOST_PIRATE_USER_CLOSE,
		NPC_MOVEMENT_STATIC,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_GHOST_PIRATE_ATTACK,
		NPC_TIMER_NONE,
		false,
		0,
		128,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_FLAMING_SKULL
		NPC_INIT_FLAMING_SKULL,
		NPC_SENSOR_FLAMING_SKULL_USER_CLOSE,
		NPC_MOVEMENT_STATIC,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_FLAMING_SKULL_ATTACK,
		NPC_TIMER_NONE,
		false,
		3,
		128,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_SHARK_MAN
		NPC_INIT_DEFAULT,
		NPC_SENSOR_GENERIC_USER_VISIBLE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_SHARK_MAN_ATTACK,
		NPC_TIMER_NONE,
		false,
		3,
		2048,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_OIL_BLOB
		NPC_INIT_DEFAULT,
		NPC_SENSOR_OIL_BLOB_USER_CLOSE,
		NPC_MOVEMENT_STATIC,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_GENERIC_USER_SEEK,
		NPC_TIMER_NONE,
		false,
		3,
		64,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_SKULL_STOMPER
		NPC_INIT_SKULL_STOMPER,
		NPC_SENSOR_SKULL_STOMPER_USER_CLOSE,
		NPC_MOVEMENT_STATIC,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_SKULL_STOMPER_ATTACK,
		NPC_TIMER_NONE,
		false,
		5,
		2048,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_MOTHER_JELLYFISH
		NPC_INIT_MOTHER_JELLYFISH,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_MOTHER_JELLYFISH,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_MOTHER_JELLYFISH_ATTACK,
		NPC_TIMER_NONE,
		false,
		3,
		256,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_SUB_SHARK
		NPC_INIT_SUB_SHARK,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_SUB_SHARK,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_SUB_SHARK_ATTACK,
		NPC_TIMER_NONE,
		false,
		3,
		256,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_FLYING_DUTCHMAN
		NPC_INIT_FLYING_DUTCHMAN,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_FLYING_DUTCHMAN,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_FLYING_DUTCHMAN_ATTACK,
		NPC_TIMER_NONE,
		false,
		3,
		256,
		false,
		DAMAGE__LAVA,
	},

	{	// NPC_IRON_DOGFISH
		NPC_INIT_IRON_DOGFISH,
		NPC_SENSOR_IRON_DOGFISH_USER_CLOSE,
		NPC_MOVEMENT_IRON_DOGFISH,
		NPC_MOVEMENT_MODIFIER_NONE,
		NPC_CLOSE_IRON_DOGFISH_ATTACK,
		NPC_TIMER_NONE,
		false,
		3,
		2048,
		false,
		DAMAGE__LAVA,
	},
};