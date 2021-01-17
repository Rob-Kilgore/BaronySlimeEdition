/*-------------------------------------------------------------------------------

BARONY
File: entity_shared.cpp
Desc: functions to be shared between editor.exe and barony.exe

Copyright 2013-2016 (c) Turning Wheel LLC, all rights reserved.
See LICENSE for details.

-------------------------------------------------------------------------------*/


#include "entity.hpp"


int checkSpriteType(Sint32 sprite)
{
	switch ( sprite )
	{
	case 71:
	case 70:
	case 62:
	case 48:
	case 36:
	case 35:
	case 30:
	case 27:
	case 10:
	case 83:
	case 84:
	case 85:
	case 86:
	case 87:
	case 88:
	case 89:
	case 90:
	case 91:
	case 92:
	case 93:
	case 94:
	case 95:
	case 75:
	case 76:
	case 77:
	// to test case 37
	case 37:
	case 78:
	case 79:
	case 80:
	case 81:
	case 82:
	case 161:
	case 163:
	case 164:
	case 165:
	case 190:
	case 191:
	case 192:
	case 193:
	case 194:
	case 195:
	case 196:
	case 197:
	case 200:
	case 201:
	case 202:
	case 203:
	case 204:
	case 205:
	case 206:
	case 217:
	case 218:
	case 219:
	case 220:
	case 222:
	case 223:
	case 224:
	case 225:
	case 226:
	case 227:
	case 228:
	case 229:
	case 230:
	case 231:
	case 232:
	case 233:
	case 234:
	case 235:
	case 236:
		//monsters
		return 1;
		break;
	case 21:
		//chest
		return 2;
		break;
	case 8:
		//items
		return 3;
		break;
	case 97:
		//summon trap
		return 4;
		break;
	case 106:
		//power crystal
		return 5;
		break;
	case 115:
		// lever timer
		return 6;
	case 102:
	case 103:
	case 104:
	case 105:
		//boulder traps
		return 7;
		break;
	case 116:
	case 166:
	case 213:
		//pedestal
		return 8;
		break;
	case 118:
		//teleporter
		return 9;
		break;
	case 119:
		//ceiling tile model
		return 10;
		break;
	case 120:
		//magic ceiling trap
		return 11;
		break;
	case 121:
	case 122:
	case 123:
	case 124:
	case 125:
	case 60:
		// Moded A_D furniture
	//case 167:// BloodyFountain
	//case 169:// BloodySpearTrap
	case 170:
	case 171:
	case 174:
	case 175:
	case 176:
	case 177:
	case 212:
		// general furniture/misc.
		return 12;
		break;
	case 127:
		// Moded A_D Floor dec
	case 168:
	case 172:
	case 173:
	case 178:
	case 208:
	case 209:
		// floor decoration
		return 13;
		break;
	case 130:
		// sound source
		return 14;
	case 131:
		// light source
		return 15;
	case 132:
		// text source
		return 16;
	case 133:
		// signal modifier
		return 17;
	case 215:
		// custom exit
		return 18;
	case 59:
		// table
		return 19;
	case 216:
		// readablebook
		return 20;
	case 2:
	case 3:
		return 21;
	case 19:
	case 20:
	case 113:
	case 114:
		return 22;
	case 1:
		return 23;
		break;
	default:
		return 0;
		break;
	}

	return 0;
}

char itemNameStrings[NUM_ITEM_STRINGS][32] =
{
	"NULL",
	"random_item",
	"wooden_shield",
	"quarterstaff",
	"bronze_sword",
	"bronze_mace",
	"bronze_axe",
	"bronze_shield",
	"sling",
	"iron_spear",
	"iron_sword",
	"iron_mace",
	"iron_axe",
	"iron_shield",
	"shortbow",
	"steel_halberd",
	"steel_sword",
	"steel_mace",
	"steel_axe",
	"steel_shield",
	"steel_shield_resistance",
	"crossbow",
	"gloves",
	"gloves_dexterity",
	"bracers",
	"bracers_constitution",
	"gauntlets",
	"gauntlets_strength",
	"cloak",
	"cloak_magicreflection",
	"cloak_invisibility",
	"cloak_protection",
	"leather_boots",
	"leather_boots_speed",
	"iron_boots",
	"iron_boots_waterwalking",
	"steel_boots",
	"steel_boots_levitation",
	"steel_boots_feather",
	"leather_breastpiece",
	"iron_breastpiece",
	"steel_breastpiece",
	"hat_phrygian",
	"hat_hood",
	"hat_wizard",
	"hat_jester",
	"leather_helm",
	"iron_helm",
	"steel_helm",
	"amulet_sexchange",
	"amulet_lifesaving",
	"amulet_waterbreathing",
	"amulet_magicreflection",
	"amulet_strangulation",
	"amulet_poisonresistance",
	"potion_water",
	"potion_booze",
	"potion_juice",
	"potion_sickness",
	"potion_confusion",
	"potion_extrahealing",
	"potion_healing",
	"potion_cureailment",
	"potion_blindness",
	"potion_restoremagic",
	"potion_invisibility",
	"potion_levitation",
	"potion_speed",
	"potion_acid",
	"potion_paralysis",
	"scroll_mail",
	"scroll_identify",
	"scroll_light",
	"scroll_blank",
	"scroll_enchantweapon",
	"scroll_enchantarmor",
	"scroll_removecurse",
	"scroll_fire",
	"scroll_food",
	"scroll_magicmapping",
	"scroll_repair",
	"scroll_destroyarmor",
	"scroll_teleportation",
	"scroll_summon",
	"magicstaff_light",
	"magicstaff_digging",
	"magicstaff_locking",
	"magicstaff_magicmissile",
	"magicstaff_opening",
	"magicstaff_slow",
	"magicstaff_cold",
	"magicstaff_fire",
	"magicstaff_lightning",
	"magicstaff_sleep",
	"ring_adornment",
	"ring_slowdigestion",
	"ring_protection",
	"ring_warning",
	"ring_strength",
	"ring_constitution",
	"ring_invisibility",
	"ring_magicresistance",
	"ring_conflict",
	"ring_levitation",
	"ring_regeneration",
	"ring_teleportation",
	"spellbook_forcebolt",
	"spellbook_magicmissile",
	"spellbook_cold",
	"spellbook_fireball",
	"spellbook_light",
	"spellbook_removecurse",
	"spellbook_lightning",
	"spellbook_identify",
	"spellbook_magicmapping",
	"spellbook_sleep",
	"spellbook_confuse",
	"spellbook_slow",
	"spellbook_opening",
	"spellbook_locking",
	"spellbook_levitation",
	"spellbook_invisibility",
	"spellbook_teleportation",
	"spellbook_healing",
	"spellbook_extrahealing",
	"spellbook_cureailment",
	"spellbook_dig",
	"gem_rock",
	"gem_luck",
	"gem_garnet",
	"gem_ruby",
	"gem_jacinth",
	"gem_amber",
	"gem_citrine",
	"gem_jade",
	"gem_emerald",
	"gem_sapphire",
	"gem_aquamarine",
	"gem_amethyst",
	"gem_fluorite",
	"gem_opal",
	"gem_diamond",
	"gem_jetstone",
	"gem_obsidian",
	"gem_glass",
	"tool_pickaxe",
	"tool_tinopener",
	"tool_mirror",
	"tool_lockpick",
	"tool_skeletonkey",
	"tool_torch",
	"tool_lantern",
	"tool_blindfold",
	"tool_towel",
	"tool_glasses",
	"tool_beartrap",
	"food_bread",
	"food_creampie",
	"food_cheese",
	"food_apple",
	"food_meat",
	"food_fish",
	"food_tin",
	"readable_book",
	"spell_item",
	"artifact_sword",
	"artifact_mace",
	"artifact_spear",
	"artifact_axe",
	"artifact_bow",
	"artifact_breastpiece",
	"artifact_helm",
	"artifact_boots",
	"artifact_cloak",
	"artifact_gloves",
	"crystal_breastpiece",
	"crystal_helm",
	"crystal_boots",
	"crystal_shield",
	"crystal_gloves",
	"vampire_doublet",
	"wizard_doublet",
	"healer_doublet",
	"mirror_shield",
	"brass_knuckles",
	"iron_knuckles",
	"spiked_gauntlets",
	"food_tomalley",
	"tool_crystalshard",
	"crystal_sword",
	"crystal_spear",
	"crystal_battleaxe",
	"crystal_mace",
	"bronze_tomahawk",
	"iron_dagger",
	"steel_chakram",
	"crystal_shuriken",
	"cloak_black",
	"magicstaff_stoneblood",
	"magicstaff_bleed",
	"magicstaff_summon",
	"tool_blindfold_focus",
	"tool_blindfold_telepathy",
	"spellbook_summon",
	"spellbook_stoneblood",
	"spellbook_bleed",
	"spellbook_reflect_magic",
	"spellbook_acid_spray",
	"spellbook_steal_weapon",
	"spellbook_drain_soul",
	"spellbook_vampiric_aura",
	"spellbook_charm",
	"potion_empty",
	"artifact_orb_blue",
	"artifact_orb_red",
	"artifact_orb_purple",
	"artifact_orb_green",
	"tunic",
	"hat_fez",
	"magicstaff_charm",
	"potion_polymorph",
	"food_blood",
	"cloak_backpack",
	"tool_alembic",
	"potion_firestorm",
	"potion_icestorm",
	"potion_thunderstorm",
	"potion_strength",
	"suede_boots",
	"suede_gloves",
	"cloak_silver",
	"hat_hood_silver",
	"hat_hood_red",
	"silver_doublet",
	"spellbook_revert_form",
	"spellbook_rat_form",
	"spellbook_spider_form",
	"spellbook_troll_form",
	"spellbook_imp_form",
	"spellbook_spray_web",
	"spellbook_poison",
	"spellbook_speed",
	"spellbook_fear",
	"spellbook_strike",
	"spellbook_detect_food",
	"spellbook_weakness",
	"mask_shaman",
	"spellbook_amplify_magic",
	"spellbook_shadow_tag",
	"spellbook_telepull",
	"spellbook_demon_illu",
	"spellbook_trolls_blood",
	"spellbook_salvage",
	"tool_whip",
	"spellbook_flutter",
	"spellbook_dash",
	"spellbook_self_polymorph",
	"spellbook_9",
	"spellbook_10",
	"magicstaff_poison",
	"tool_metal_scrap",
	"tool_magic_scrap",
	"tool_tinkering_kit",
	"tool_sentrybot",
	"tool_repairkit",
	"tool_fire_bomb",
	"tool_sleep_bomb",
	"tool_freeze_bomb",
	"tool_teleport_bomb",
	"tool_gyrobot",
	"tool_spellbot",
	"tool_decoy",
	"tool_dummybot",
	"machinist_apron",
	"enchanted_feather",
	"punisher_hood",
	"scroll_charging",
	"quiver_sharp",
	"quiver_pierce",
	"quiver_lightweight",
	"quiver_fire",
	"quiver_heavy",
	"quiver_crystal",
	"quiver_hunting",
	"longbow",
	"compound_bow",
	"heavy_crossbow",
	"boomerang",
	"scroll_conjurearrow",
	"tool_greentorch",
	"hat_hood_yellowgreen",
	"cloak_yellowgreen",
	"abyssal_helm",
	"abyssal_boots",
	"abyssal_knuckles",
	"abyssal_breastpiece",
	"abyssal_cloak",
	"abyssal_sword",
	"abyssal_axe",
	"abyssal_mace",
	"abyssal_spear",
	"abyssal_crossbow",
	"abyssal_shield",
	"abyssal_ring",
	"abyssal_amulet",
	"hat_wizard_smily",
	"iron_breastpiece_smily",
	"cloak_elementalist",
	"food_cheddarcheesewheel",
	"food_banana",
	"food_pizza",
	"food_salmon",
	"food_hamletdiner",
	"spellbook_deathcoil",
	"bone_spear",
	"symbol_rage",
	"symbol_cruelty",
	"symbol_hatred",
	"ice_gloves",
	"boots_lightness",
	"boots_super_lightness",
	"cloak_melting",
	"ring_randomness",
	"food_anglerfish",
	"food_tentaclepie",
	"tool_unihorn",
	"abyssal_mask",
	"executioner_axe",
	"granite_maul",
	"trident",
	"rapier",
	"cannon",
	"cannon_boulder",
	"necro_shield",
	"makeshift_bow",
	"wood_hammer",
	"machete",
	"stone_axe",
	"hat_tophat",
	"inquisitor_ring",
	"inquisitor_mask",
	"inquisitor_amulet",
	"inquisitor_lantern",
	"inquisitor_helm",
	"inquisitor_boots",
	"inquisitor_gloves",
	"inquisitor_breastpiece",
	"inquisitor_backpack",
	"inquisitor_spear",
	"inquisitor_sword",
	"inquisitor_axe",
	"inquisitor_hammer",
	"inquisitor_bow",
	"mask_googly",
	"mask_grid",
	"mask_angry",
	"mask_eye",
	"anti_sleep_shield",
	"anti_charm_shield",
	"anti_bleed_shield",
	"punching_helm",
	"elementalist_hat",
	"elementalist_doublet",
	"lizard_leather_breastpiece",
	"lifesteal_knucles",
	"mana_gloves",
	"flying_shoes",
	"food_tomato",
	"food_cabbage",
	"food_pear",
	"chain_robes",
	"chain_robes_aqua",
	"marble_breastpiece",
	"tin_helm",
	"tin_breastpiece",
	"tin_gloves",
	"tin_boots",
	"tool_candle",
	"tool_candle_timeless",
	"lost_ring",
	"lost_amulet",
	"lost_mask",
	"lost_polearm",
	"lost_axe",
	"lost_mace",
	"lost_sword",
	"lost_bow",
	"lost_shield",
	"lost_helm",
	"lost_breastpiece",
	"lost_gauntlets",
	"lost_boots",
	"lost_cloak",
	"golden_key",
	"sacrificial_dagger",
	"quiver_ice",
	"cross_antilich",
	"spellbook_ultrahealing",
	"amulet_manabound",
	"scoll_legend",
	"needle",
	""
};

char itemStringsByType[10][NUM_ITEM_STRINGS_BY_TYPE][32] =
{
	{
		"NULL",
		"random_item",
		"hat_phrygian",
		"hat_hood",
		"hat_wizard",
		"hat_jester",
		"hat_fez",
		"hat_hood_silver",
		"hat_hood_red",
		"mask_shaman",
		"punisher_hood",
		"leather_helm",
		"iron_helm",
		"steel_helm",
		"crystal_helm",
		"artifact_helm",
		"hat_hood_yellowgreen",
		"abyssal_helm",
		"hat_wizard_smily",
		"hat_tophat",
		"inquisitor_helm",
		"punching_helm",
		"elementalist_hat",
		"tin_helm",
		"lost_helm",
		""
	},
	{
		"NULL",
		"random_item",
		"quarterstaff",
		"bronze_sword",
		"bronze_mace",
		"bronze_axe",
		"sling",
		"iron_spear",
		"iron_sword",
		"iron_mace",
		"iron_axe",
		"shortbow",
		"steel_halberd",
		"steel_sword",
		"steel_mace",
		"steel_axe",
		"crystal_sword",
		"crystal_spear",
		"crystal_battleaxe",
		"crystal_mace",
		"crossbow",
		"bronze_tomahawk",
		"iron_dagger",
		"steel_chakram",
		"crystal_shuriken",
		"boomerang",
		"longbow",
		"compound_bow",
		"heavy_crossbow",
		"potion_water",
		"potion_booze",
		"potion_juice",
		"potion_sickness",
		"potion_confusion",
		"potion_extrahealing",
		"potion_healing",
		"potion_cureailment",
		"potion_blindness",
		"potion_restoremagic",
		"potion_invisibility",
		"potion_levitation",
		"potion_speed",
		"potion_acid",
		"potion_paralysis",
		"potion_polymorph",
		"potion_firestorm",
		"potion_icestorm",
		"potion_thunderstorm",
		"potion_strength",
		"magicstaff_light",
		"magicstaff_digging",
		"magicstaff_locking",
		"magicstaff_magicmissile",
		"magicstaff_opening",
		"magicstaff_slow",
		"magicstaff_cold",
		"magicstaff_fire",
		"magicstaff_lightning",
		"magicstaff_sleep",
		"magicstaff_stoneblood",
		"magicstaff_bleed",
		"magicstaff_summon",
		"magicstaff_charm",
		"magicstaff_poison",
		"spellbook_forcebolt",
		"spellbook_magicmissile",
		"spellbook_cold",
		"spellbook_fireball",
		"spellbook_light",
		"spellbook_removecurse",
		"spellbook_lightning",
		"spellbook_identify",
		"spellbook_magicmapping",
		"spellbook_sleep",
		"spellbook_confuse",
		"spellbook_slow",
		"spellbook_opening",
		"spellbook_locking",
		"spellbook_levitation",
		"spellbook_invisibility",
		"spellbook_teleportation",
		"spellbook_healing",
		"spellbook_extrahealing",
		"spellbook_cureailment",
		"spellbook_summon",
		"spellbook_stoneblood",
		"spellbook_bleed",
		"spellbook_dig",
		"spellbook_reflect_magic",
		"spellbook_acid_spray",
		"spellbook_steal_weapon",
		"spellbook_drain_soul",
		"spellbook_vampiric_aura",
		"spellbook_charm",
		"spellbook_revert_form",
		"spellbook_rat_form",
		"spellbook_spider_form",
		"spellbook_troll_form",
		"spellbook_imp_form",
		"spellbook_spray_web",
		"spellbook_poison",
		"spellbook_speed",
		"spellbook_fear",
		"spellbook_strike",
		"spellbook_detect_food",
		"spellbook_weakness",
		"spellbook_amplify_magic",
		"spellbook_shadow_tag",
		"spellbook_telepull",
		"spellbook_demon_illu",
		"spellbook_trolls_blood",
		"spellbook_salvage",
		"spellbook_flutter",
		"spellbook_dash",
		"spellbook_self_polymorph",
		"spellbook_9",
		"spellbook_10",
		"tool_whip",
		"tool_pickaxe",
		"artifact_sword",
		"artifact_mace",
		"artifact_spear",
		"artifact_axe",
		"artifact_bow",
		"artifact_orb_blue",
		"artifact_orb_red",
		"artifact_orb_purple",
		"artifact_orb_green",
		"abyssal_sword",
		"abyssal_axe",
		"abyssal_mace",
		"abyssal_spear",
		"abyssal_crossbow",
		"spellbook_deathcoil",
		"bone_spear",
		"symbol_rage",
		"symbol_cruelty",
		"symbol_hatred",
		"executioner_axe",
		"granite_maul",
		"trident",
		"rapier",
		"cannon",
		"cannon_boulder",
		"makeshift_bow",
		"wood_hammer",
		"machete",
		"stone_axe",
		"inquisitor_spear",
		"inquisitor_sword",
		"inquisitor_axe",
		"inquisitor_hammer",
		"inquisitor_bow",
		"lost_polearm",
		"lost_axe",
		"lost_mace",
		"lost_sword",
		"lost_bow",
		"cross_antilich",
		"spellbook_ultrahealing",
		"needle",
		""
	},
	{
		"NULL",
		"random_item",
		"wooden_shield",
		"bronze_shield",
		"iron_shield",
		"steel_shield",
		"steel_shield_resistance",
		"crystal_shield",
		"mirror_shield",
		"tool_torch",
		"tool_lantern",
		"tool_crystalshard",
		"quiver_sharp",
		"quiver_pierce",
		"quiver_lightweight",
		"quiver_fire",
		"quiver_heavy",
		"quiver_crystal",
		"quiver_hunting",
		"tool_greentorch",
		"abyssal_shield",
		"necro_shield",
		"inquisitor_lantern",
		"anti_sleep_shield",
		"anti_charm_shield",
		"anti_bleed_shield",
		"tool_candle",
		"tool_candle_timeless",
		"lost_shield",
		"quiver_ice",
		""
	},
	{
		"NULL",
		"random_item",
		"leather_breastpiece",
		"iron_breastpiece",
		"steel_breastpiece",
		"crystal_breastpiece",
		"artifact_breastpiece",
		"vampire_doublet",
		"wizard_doublet",
		"healer_doublet",
		"tunic",
		"silver_doublet",
		"machinist_apron",
		"abyssal_cheastpiece",
		"iron_breastpiece_slimy",
		"inquisitor_breastpiece",
		"lizard_leather_breastpiece",
		"elementalist_doublet",
		"chain_robes",
		"chain_robes_aqua",
		"marble_breastpiece",
		"tin_breastpiece",
		"lost_breastpiece",
		""
	},
	{
		"NULL",
		"random_item",
		"leather_boots",
		"leather_boots_speed",
		"iron_boots",
		"iron_boots_waterwalking",
		"steel_boots",
		"steel_boots_levitation",
		"steel_boots_feather",
		"crystal_boots",
		"artifact_boots",
		"suede_boots",
		"abyssal_boots",
		"boots_lightness",
		"boots_super_lightness",
		"inquisitor_boots",
		"flying_shoes",
		"tin_boots",
		"lost_boots",
		""
	},
	{
		"NULL",
		"random_item",
		"ring_adornment",
		"ring_slowdigestion",
		"ring_protection",
		"ring_warning",
		"ring_strength",
		"ring_constitution",
		"ring_invisibility",
		"ring_magicresistance",
		"ring_conflict",
		"ring_levitation",
		"ring_regeneration",
		"ring_teleportation",
		"abyssal_ring",
		"ring_randomness",
		"inquisitor_ring",
		"lost_ring",
		""
	},
	{
		"NULL",
		"random_item",
		"amulet_sexchange",
		"amulet_lifesaving",
		"amulet_waterbreathing",
		"amulet_magicreflection",
		"amulet_strangulation",
		"amulet_poisonresistance",
		"abyssal_amulet",
		"inquisitor_amulet",
		"lost_amulet",
		"amulet_manabound",
		""
	},
	{
		"NULL",
		"random_item",
		"cloak",
		"cloak_black",
		"cloak_silver",
		"cloak_magicreflection",
		"cloak_invisibility",
		"cloak_protection",
		"artifact_cloak",
		"cloak_backpack",
		"cloak_yellowgreen",
		"abyssal_cloak",
		"cloak_elementalist",
		"cloak_melting",
		"inquisitor_backpack",
		"lost_cloak",
		""
	},
	{
		"NULL",
		"random_item",
		"tool_blindfold",
		"tool_glasses",
		"tool_blindfold_focus",
		"tool_blindfold_telepathy",
		"abyssal_mask",
		"inquisitor_mask",
		"mask_googly",
		"mask_grid",
		"mask_angry",
		"mask_eye",
		"lost_mask",
		""
	},
	{
		"NULL",
		"random_item",
		"gloves",
		"gloves_dexterity",
		"bracers",
		"bracers_constitution",
		"gauntlets",
		"gauntlets_strength",
		"crystal_gloves",
		"artifact_gloves",
		"brass_knuckles",
		"iron_knuckles",
		"spiked_gauntlets",
		"suede_gloves",
		"abyssal_knuckles",
		"ice_gloves",
		"inquisitor_gloves",
		"lifesteal_knucles",
		"mana_gloves",
		"tin_gloves",
		"lost_gauntlets",
		""
	}
	
};

char spriteEditorNameStrings[NUM_EDITOR_SPRITES][64] =
{
	"NULL",	
	"PLAYER START",
	"DOOR (East-West)",
	"DOOR (North-South)",
	"TORCH (West Wall)",
	"TORCH (North Wall)",
	"TORCH (East Wall)",
	"TORCH (South Wall)",
	"ITEM",
	"GOLD",
	"RANDOM (Dependent on Level)",
	"LADDER",
	"FIREPLACE",
	"Flame Sprite (Not Used)",
	"FOUNTAIN",
	"SINK",
	"Flame Sprite (Not Used)",
	"Lever",
	"Wire",
	"GATE (North-South)",
	"GATE (East-West)",
	"CHEST",
	"NOT USED",
	"NOT USED",
	"NOT USED",
	"NOT USED",
	"NOT USED",
	"HUMAN",
	"NOT USED",
	"NOT USED",
	"TROLL",
	"NOT USED",
	"ARROW TRAP",
	"PRESSURE PLATE",
	"PRESSURE PLATE (Latch On)",
	"SHOPKEEPER",
	"GOBLIN",
	"MINOTAUR SPAWN TRAP",
	"BOULDER TRAP",
	"HEADSTONE",
	"NULL",
	"LAVA",
	"NOT USED",
	"LADDER HOLE",
	"BOULDER",
	"PORTAL",
	"SECRET LADDER",
	"NOT USED",
	"SPIDER",
	"NOT USED",
	"NOT USED",
	"NOT USED",
	"NOT USED",
	"NOT USED",
	"NOT USED",
	"NOT USED",
	"NOT USED",
	"NOT USED",
	"NOT USED",
	"TABLE",
	"CHAIR",
	"DIAMOND PICKAXE",
	"LICH",
	"END PORTAL",
	"SPEAR TRAP",
	"MAGIC TRAP",
	"WALL BUSTER",
	"WALL BUILDER",
	"MAGIC BOW",
	"MAGIC SPEAR",
	"GNOME",
	"DEVIL",
	"DEVIL TELEPORT LOCATION",
	"DEVIL TELEPORT LOCATION",
	"DEVIL TELEPORT LOCATION",
	"DEMON",
	"IMP",
	"MINOTAUR",
	"SCORPION",
	"SLIME",
	"SUCCUBUS",
	"RAT",
	"GHOUL",
	"SKELETON",
	"KOBOLD",
	"SCARAB",
	"CRYSTALGOLEM",
	"INCUBUS",
	"VAMPIRE",
	"SHADOW",
	"COCKATRICE",
	"INSECTOID",
	"GOATMAN",
	"AUTOMATON",
	"LICH ICE",
	"LICH FIRE",
	"NOT USED",
	"SUMMON TRAP",
	"CRYSTAL SHARD (West Wall)",
	"CRYSTAL SHARD (North Wall)",
	"CRYSTAL SHARD (East Wall)",
	"CRYSTAL SHARD (South Wall)",
	"BOULDER TRAP SINGLE (Roll East)",
	"BOULDER TRAP SINGLE (Roll South)",
	"BOULDER TRAP SINGLE (Roll West)",
	"BOULDER TRAP SINGLE (Roll North)",
	"POWER CRYSTAL",
	"ARMED BEAR TRAP",
	"STALAG-COLUMN",
	"STALAGMITE SINGLE",
	"STALAGMITE MULTIPLE",
	"STALAGTITE SINGLE",
	"STALAGTITE MULTIPLE",
	"GATE INVERTED (North-South)",
	"GATE INVERTED (East-West)",
	"LEVER WITH TIMER",
	"PEDESTAL",
	"MID PORTAL",
	"TELEPORTER",
	"CEILING TILE MODEL",
	"SPELL TRAP CEILING",
	"ARCANE CHAIR",
	"ARCANE BED",
	"BUNK BED",
	"COLUMN DECO",
	"PODIUM",
	"PISTONS",
	"DECORATION",
	"TELEPORT LOCATION",
	"ENDEND PORTAL",
	"SOUND SOURCE",
	"LIGHT SOURCE",
	"TEXT SOURCE",
	"SIGNAL TIMER",
	"1",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	"COCKROACH",
	"NOT USED",
	"BURG GUARD",
	"GARGOYLE",
	"MATILDA",
	"PEDESTAL SYMBOLS",
	"BLOODY FOUNTAIN",
	"BLOODY ROCK",
	"BLOODY SPEAR TRAP",
	"BLUE BED",
	"BLUE CHAIR",
	"FLOOR GRASS SNOW",
	"SEWER GARBAGE",
	"SEWER PILLAR",
	"STOL",
	"GREEN PODIUM",
	"ACID SPRAY TRAP",
	"FLOOR GRASS PURPLE",
	"PORTAL JUMP 2",
	"PORTAL JUMP 8",
	"LADDER JUMP 2",
	"LADDER JUMP 7",
	"LADDER JUMP 8",
	"LADDER JUMP 9",
	"LADDER JUMP 10",
	"LADDER JUMP 16",
	"LADDER JUMP 14",
	"MID PORTAL JUMP 13",
	"MID PORTAL 2",
	"CRYORUNE",
	"YETI",
	"ICEDEMON",
	"EYEBALL",
	"FLESHLING",
	"ABOMINATION",
	"CHLOROSH",
	"LICH_FALLEN",
	"ABYSS COLUMN BLOCK",
	"END PORTAL ABYSS",
	"ANT",
	"DUST DEVIL",
	"PARASITE",
	"METALLIC BEAST",
	"SKU-LIT",
	"RAN-GIC",
	"WAN-RIT",
	"NOT USED AngelFlame",
	"GRASS VINES",
	"TALL WHEAT",
	"MARBLE GATE (North-South)",
	"MARBLE GATE (East-West)",
	"METAL TABLE",
	"PEDESTAL LOCK",
	"",
	"CUSTOM EXIT",
	"READABLE BOOK",
	"SENTRYBOT",
	"SPELLBOT",
	"DUMMYBOT",
	"GYROBOT",
	"UNUSED",
	"FROGMAN",
	"BIG WOG",
	"WEREWOLF",
	"GREY WEREWOLF",
	"BANSHEE",
	"WILL O' THE WISP",
	"CROW",
	"ENT",
	"LIVING JACK O' LANTERN",
	"MR. SCARECROW",
	"GINEVRA",
	"GRETTA",
	"GRIMELDA",
	"CULTIST",
	"FLESH GOLEM",
	"HAG HOUSE DOOR (East-West)",
	"HAG HOUSE DOOR (North-South)",
	"CAULDRON",
	"TALL CORN",
	"DEAD SKELETON",
	"DEAD TREE",
	"BLUE GRASS",
	"DARK FOUNTAIN",
	"HEAD ON STICK SHORT",
	"HEAD ON STICK TALL",
	"JACK O' LANTERN",
	"DARK PEDESTAL",
	"PILLAR BOTTOM",
	"PILLAR TWO",
	"PILLAR THREE",
	"PILLAR TOP",
	"ROADSIDE FENCE",
	"ROADSIDE LANTERN",
	"ROCK PILLAR",
	"ROCK 1",
	"ROCK 2",
	"ROCK 3",
	"SIGNPOST",
	"SKULL DECORATION",
	"WITCH TABLE",
	"BIG BIG CHUNGUS"
};

char monsterEditorNameStrings[NUMMONSTERS][17] =
{
	"nothing",
	"human",
	"rat",
	"goblin",
	"slime",
	"troll",
	"invalid",
	"spider",
	"ghoul",
	"skeleton",
	"scorpion",
	"imp",
	"invalid",
	"gnome",
	"demon",
	"succubus",
	"invalid",
	"lich",
	"minotaur",
	"devil",
	"shopkeeper",
	"kobold",
	"scarab",
	"crystalgolem",
	"incubus",
	"vampire",
	"shadow",
	"cockatrice",
	"insectoid",
	"goatman",
	"automaton",
	"lich_ice",
	"lich_fire",
	"sentrybot",
	"spellbot",
	"gyrobot",
	"dummybot",
	"cockroach",
	"burgguard",
	"gargoyle",
	"matilda",
	"cryorune",
	"yeti",
	"icedemon",
	"eyeball",
	"fleshling",
	"abomination",
	"chlorosh",
	"lichfallen",
	"ant",
	"dustDevil",
	"parasite",
	"metallicBeast",
	"sku-lit",
	"ran-gic",
	"wan-rit",
	"frogman",
	"bigwog",
	"werewolf",
	"greywerewolf",
	"banshee",
	"willothewisp",
	"crow",
	"ent",
	"jackolantern",
	"mrscarecrow",
	"ginevra",
	"gretta",
	"grimelda",
	"cultist",
	"fleshgolem"
};

char tileEditorNameStrings[NUM_EDITOR_TILES][44] =
{
	"backdrop.png",
	"bback.png",
	"bbrick.png",
	"greenbrick.png",
	"graysquare.png",
	"sand.png",
	"rock.png",
	"arrow.png",
	" Smooth Stone Wall.png",
	" Wood.png",
	" Cobblestone Mine Wall.png",
	" Cobblestone Mine Support Wall.png",
	"Gray Brick.png",
	"Dirt.png",
	"Grass.png",
	"Green Cobblestone.png",
	"Red Diamond Tiles.png",
	"Blue Pillar.png",
	"Tan Brick Wall.png",
	"Mossy Tan Brick Wall.png",
	"Red Cobblestone Mine Wall.png",
	"Red Cobblestone Mine Support Wall.png",
	"water1.png",
	"water2.png",
	"water3.png",
	"water4.png",
	"water5.png",
	"water6.png",
	"water7.png",
	"water8.png",
	"Plank Ceiling.png",
	"Plankand Rafter Ceiling.png",
	"Fancy Brick Wall.png",
	"Fancy Gray Brick Wall.png",
	"sandfloor.png",
	"sandfloordark.png",
	"graytiles.png",
	"Roots.png",
	"greenbrick Crack.png",
	"Green Cobblestone Vine.png",
	"Green Cobblestone No Grass.png",
	"rd A.png",
	"rd B.png",
	"rd C.png",
	"rd D.png",
	"rd E.png",
	"rd F.png",
	"rd G.png",
	"rd H.png",
	"rd I.png",
	"Hard Stone.png",
	"Plankand Rafter Ceiling Horiz.png",
	"Red Square Tiles.png",
	"Trap Wall.png",
	"shopsign.png",
	"Shelf.png",
	"Dirt Two.png",
	"Purple Square Tiles.png",
	"Grass Two.png",
	"Purple Diamond Tiles.png",
	"Dull Green Brick.png",
	"Dull Green Brick Skull.png",
	"Dull Green Square.png",
	"Gray Dirt.png",
	"Lava1.png",
	"Lava2.png",
	"Lava3.png",
	"Lava4.png",
	"Lava5.png",
	"Lava6.png",
	"Lava7.png",
	"Lava8.png",
	"Big Orange Stone.png",
	"Red Pillar.png",
	"Red Brick.png",
	"Red Square.png",
	"Red Brick Face.png",
	"clouds.png",
	"Magic Trap Wall1.png",
	"Magic Trap Wall2.png",
	"Magic Trap Wall3.png",
	"Magic Trap Wall4.png",
	"clouds.png",
	"Leaves.png",
	"Cobblestone.png",
	"Cobblestone Mine Support Sides.png",
	"Cobblestone Mine Support Side L.png",
	"Cobblestone Mine Support Side R.png",
	"Cobblestone Mine Wall Two.png",
	"Cobblestone Mossy.png",
	"Cobblestone Mine Support Wall Mossy.png",
	"Cobblestone Mine Support Sides Mossy.png",
	"Cobblestone Mine Wall Mossy.png",
	"Cobblestone Mine Wall Two Mossy.png",
	"Red Cobblestone Mine Wall Support Sides.png",
	"Red Cobblestone Mine Wall Support L.png",
	"Red Cobblestone Mine Wall Support R.png",
	"Wood Two.png",
	"Wood Corner NE.png",
	"Wood Corner NW.png",
	"Wood Corner SE.png",
	"Wood Corner SW.png",
	"Plankand Rafter Ceiling Cross.png",
	"Gray Brick Block.png",
	"Gray Brick Columns.png",
	"Gray Brick Column R.png",
	"Gray Brick Column L.png",
	"Gray Brick Column Center.png",
	"Swamp Logs.png",
	"Swamp Logs Two.png",
	"Swamp Log Ends.png",
	"Roots Treetop.png",
	"Swamp Log L.png",
	"Swamp Log R.png",
	"greenbricktwo.png",
	"Green Cobblestone Two.png",
	"Green Cobblestone Column.png",
	"Green Cobblestone Column No Grass.png",
	"Fancy Sandstone Wall.png",
	"Orange Square Tiles.png",
	"Ruin Tiles.png",
	"Red Brick Face1.png",
	"Red Brick Face2.png",
	"Red Brick Face3.png",
	"Red Brick Face4.png",
	"Red Brick Face5.png",
	"Red Brick Face6.png",
	"Red Brick Face7.png",
	"Hell Tiles.png",
	"Skull Lava1.png",
	"Skull Lava2.png",
	"Skull Lava3.png",
	"Skull Lava4.png",
	"Skull Lava5.png",
	"Skull Lava6.png",
	"bonewall.png",
	"Lavafall1.png",
	"Lavafall2.png",
	"Lavafall3.png",
	"bonewallwithgrass.png",
	"bonewallpillar.png",
	"decayedstone.png",
	"Dirt Path -  E.png",
	"Dirt Path -  S.png",
	"Dirt Path -  W.png",
	"Dirt Path -  N.png",
	"Dirt Path -  NE.png",
	"Dirt Path -  SE.png",
	"Dirt Path -  SW.png",
	"Dirt Path -  NW.png",
	"Dirt Path -  NE O.png",
	"Dirt Path -  SE O.png",
	"Dirt Path -  SW O.png",
	"Dirt Path -  NW O.png",
	"Cave Floor.png",
	"Cave Floor Rough.png",
	"Cave Wall.png",
	"Cave Wall Decor.png",
	"Cave Wall Crystal.png",
	"Cave Wall Reinforced.png",
	"Cave Wall Reinforced Left.png",
	"Cave Wall Reinforced Right.png",
	"Cave Wall Reinforced Center.png",
	"Cave Wall Reinforced High.png",
	"Cave Wall Alcove.png",
	"Cave Wall Columns.png",
	"Cave Wall Column Center.png",
	"Cave Wall Column Left.png",
	"Cave Wall Column Right.png",
	"Caves To Crystal Wall Left.png",
	"Caves To Crystal Wall Right.png",
	"Caves To Crystal Floor -  W.png",
	"Caves To Crystal Floor -  E.png",
	"Caves To Crystal Floor -  S.png",
	"Caves To Crystal Floor -  N.png",
	"Caves To Crystal Floor -  SW.png",
	"Caves To Crystal Floor -  NW.png",
	"Caves To Crystal Floor -  SE.png",
	"Caves To Crystal Floor -  NE.png",
	"Caves To Crystal Floor -  SW O.png",
	"Caves To Crystal Floor -  NW O.png",
	"Caves To Crystal Floor -  SE O.png",
	"Caves To Crystal Floor -  NE O.png",
	"Crystal Floor.png",
	"Crystal Floor Rough.png",
	"Crystal Wall.png",
	"Crystal Wall Decor1.png",
	"Crystal Wall Decor2.png",
	"Crystal Wall Decor3.png",
	"Crystal Wall Decor4.png",
	"Crystal Wall Reinforced.png",
	"Crystal Wall Reinforced Left.png",
	"Crystal Wall Reinforced Right.png",
	"Crystal Wall Reinforced Center.png",
	"Crystal Wall Reinforced High.png",
	"Crystal Wall Columns.png",
	"Crystal Wall Column Center.png",
	"Crystal Wall Column Left.png",
	"Crystal Wall Column Right.png",
	"Bronze Columns.png",
	"Bronze Columns Alcove.png",
	"Submap.png",
	"Cave Wall Reinforced No Beam.png",
	"Cave Wall Reinforced Left Cap.png",
	"Cave Wall Reinforced Right Cap.png",
	"Crystal Wall Reinforced No Beam.png",
	"Crystal Wall Reinforced Left Cap.png",
	"Crystal Wall Reinforced Right Cap.png",
	"Crystal Floor Trap 1.png",
	"Crystal Floor Trap 2.png",
	"Crystal Floor Trap 3.png",
	"Crystal Floor Trap 4.png",
	"Arcane Crystal H.png",
	"Arcane Crystal J.png",
	"Arcane Crystal Plating.png",
	"Arcane Crystal Tile.png",
	"Arcane Crystal V.png",
	"Arcane Panel Blue.png",
	"Arcane Panel BlueOpen.png",
	"Arcane Panel Gold.png",
	"Arcane Panel GoldOpen.png",
	"Arcane Pipes Blue.png",
	"Arcane Pipes Blue H.png",
	"Arcane Pipes Blue J.png",
	"Arcane Pipes Blue Plating.png",
	"Arcane Pipes Blue Plating Decor.png",
	"Arcane Pipes Blue V.png",
	"Arcane Pipes Gold.png",
	"Arcane Pipes Gold H.png",
	"Arcane Pipes Gold J.png",
	"Arcane Pipes Gold Plating.png",
	"Arcane Pipes Gold Plating Decor.png",
	"Arcane Pipes Gold V.png",
	"Bronze Column Pipe.png",
	"Sky.png",
	"SkyCrackle.png",
	"SkyCrackle_B.png",
	"BigYellowSquare.png",
	"OldGrid.png",
	"OldGridwat1.png",
	"OldGridwat2.png",
	"OldGridwat3.png",
	"OldGridwat4.png",
	"OldGridwat5.png",
	"OldGridwat6.png",
	"OldGridwat7.png",
	"OldGridwat8.png",
	"SewerPipesLong.png",
	"SewerPipesMachine.png",
	"MossPoison1.png",
	"MossPoison2.png",
	"MossPoison3.png",
	"MossPoison4.png",
	"GrossSquare.png",
	"GrosseBrick.png",
	"CobblestoneGross.png",
	"GrossBrickSkull.png",
	"Fungus.png",
	"GreenCobblestoneTomb.png",
	"PurpleGrass.png",
	"PurpleRoots.png",
	"PurpleRootsTreetop.png",
	"PurpleLeaves.png",
	"FrostTiles.png",
	"FrostyPlankCeiling.png",
	"GrayWood.png",
	"GrayWoodTwo.png",
	"GrayWoodCornerNE.png",
	"GrayWoodCornerNw.png",
	"GrayWoodCornerSE.png",
	"GrayWoodCornerSW.png",
	"CatedralBrick.png",
	"CatedralBrickCandles.png",
	"CatedralAltar.png",
	"Mossshopsign.png",
	"EmptyShelf.png",
	"RedCrakedSquare.png",
	"BlackBrick.png",
	"BlackPillar.png",
	"BloodyFloor.png",
	"BloodyFloorParasite.png",
	"BloodyWall.png",
	"FleshWall.png",
	"SkyOrganic.png",
	"Whitesquare.png",
	"SpiderWebWall.png",
	"SpiderWebCelling.png",
	"SpiderWebWall1.png",
	"SpiderWebWall2.png",
	"SpiderWebWall3.png",
	"SpiderWebWall4.png",
	"SpiderWebWall5.png",
	"SpiderWebWall6.png",
	"SpiderWebfloor.png",
	"Acidtiles.png",
	"AcidtilesCracked.png",
	"Acidtilesbroken.png",
	"Acidtilesacidpool.png",
	"AcidtilesCircle.png",
	"AcidGrid1.png",
	"AcidGrid2.png",
	"AcidGrid3.png",
	"AcidGrid4.png",
	"AcidStoneWall.png",
	"AcidStoneDrop1.png",
	"AcidStoneDrop2.png",
	"AcidStoneDrop3.png",
	"AcidStoneDrop4.png",
	"FancySlimystoneWall.png",
	"BurgPlageBlock.png",
	"GrossTile.png",
	"AcidTrapWall1.png",
	"AcidTrapWall2.png",
	"AcidTrapWall3.png",
	"AcidTrapWall4.png",
	"Greenishbrick.png",
	"SnowGrass.png",
	"ColdPath.png",
	"MountainWall",
	"MountainWallLayers",
	"PineLeaves",
	"Pine",
	"CyanSquare",
	"Frozenwat1",
	"Frozenwat2",
	"Frozenwat3",
	"Frozenwat4",
	"Frozenwat5",
	"Frozenwat6",
	"Frozenwat7",
	"Frozenwat8",
	"SolidIce.png",
	"DarkBlueStone.png",
	"ColdGrayBrick.png",
	"ColdGrayFloor.png",
	"ColdGrayFloorIce.png",
	"GrayBrickCracked.png",
	"CrackShine1.png",
	"CrackShine2.png",
	"CrackShine3.png",
	"FancyTundraWall.png",
	"TransparantIce.png",
	"IcefallStone.png",
	"IceStoneDrop1.png",
	"IceStoneDrop2.png",
	"IceStoneDrop3.png",
	"IceStoneDrop4.png",
	"WBdimond.png",
	"WBdemonface.png",
	"ColdDungeon.png",
	"WoodTundra.png",
	"PineLogs.png",
	"Snow.png",
	"FrozenCreature.png",
	"BlackBrickCatabombLeft.png", 
	"BlackBrickCatabombRight.png", 
	"BloodLantern1.png", 
	"BloodLantern2.png", 
	"BloodLantern3.png", 
	"BloodLantern4.png", 
	"CatacombSquareTiles.png", 
	"DarkGraySquareTiles.png", 
	"Dot.png", 
	"faceWall.png", 
	"GhostPlatform.png", 
	"GrassCreepy.png",
	"GrassCreepyEmblam.png", 
	"GrassCreepyTwitch1.png", 
	"GrassCreepyTwitch2.png", 
	"grayredsquare.png", 
	"HardStoneCellingOfHorrors.png", 
	"MetalWall.png", 
	"Mouth.png", 
	"MuralofPortalsLB.png", 
	"MuralofPortalsLT.png", 
	"MuralofPortalsMB.png", 
	"MuralofPortalsMT.png", 
	"MuralofPortalsRB.png", 
	"MuralofPortalsRT.png", 
	"NecropolisStreet.png", 
	"RedVeinSquare.png",
	"Rootenground.png", 
	"Skullfacewall.png", 
	"SoulPilar1water.png",
	"SoulPilar2water.png",
	"SoulPilar3water.png",
	"SoulPilar4water.png",
	"SoulPilar5water.png",
	"SoulPilar6water.png",
	"SoulPilar7water.png",
	"SoulPilar8water.png", 
	"WatchingCelling.png", 
	"AbyssFloor.png", 
	"AbyssFloorColor.png", 
	"AbyssWall.png", 
	"AbyssLeak.png",
	"AbyssPillar.png",
	"BlackGridTile.png",
	"AbyssLast.png",
	"AbyssLastWall.png",
	"AbyssLastWallB.png",
	"SkyWickedA.png",
	"SkyWickedB.png",
	"SkyWickedC.png",
	"SkyWickedD.png",
	"SkyWickedE.png",
	"SkyWickedF.png",
	"Necrohousetiles.png",
	"NecroHouseWall.png",
	"NecroSquareTiles.png",
	"NecroPlankCeiling.png",
	"NecroDirt.png",
	"DeepSeaSquare.png",
	"AbyssColumnsAlcove.png",
	"AbyssColumns.png",
	"ChloroshSeed.png", 
	"ChloroshLeaves.png",
	"GhostPlatformArrow1.png",
	"GhostPlatformArrow2.png",
	"GhostPlatformArrow3.png",
	"GhostPlatformArrow4.png",
	"GhostPlatformArrow5.png",
	"GhostPlatformArrow6.png",
	"GrayGrass.png",
	"AbyssFancyFloor.png",
	"AbyssFancyCeiling.png",
	"SkyWickedBlank.png",
	"AbyssMid.png",
	"MarblePillarTop.png",
	"MarblePillarMid.png", 
	"MarblePillarBot.png", 
	"MarbleWall.png", 
	"MarbleWallTop.png", 
	"MarbleWallCrack.png",
	"MarbleCrystalSquare.png",
	"MarbleFloor.png",
	"MarbleCryptic.png",
	"MarblePathH.png", 
	"MarblePathV.png",
	"MarbleCrystalCircle.png",
	"MarbleCeiling.png", 
	"TimeFragmentTop.png",
	"TimeFragmentMid.png",
	"TimeFragmentBot.png",
	"MarblePathLargeVR.png",
	"MarblePathLargeVL.png",
	"MarblePathLargeHT.png",
	"MarblePathLargeHB.png",
	"TimeFragmentClean.png",
	"MarbleLineH.png",
	"MarbleLineV.png",
	"VaultFloor.png",
	"GoldTiles.png",
	"VaultWall.png",
	"VaultStone.png", 
	"VaultGold.png",
	"AntDirt.png",
	"AntNestWall.png",
	"AntNestFallingWall.png",
	"SmothBrownRock.png", 
	"LoyalTiles.png",
	"WoodYellow.png",
	"RoundBrownBrick.png", 
	"RoundBrownBrickSand.png",
	"AntEggs.png", 
	"FarmNorth.png", 
	"Farm.png",
	"FarmSouth.png", 
	"ShelfBoxes.png",
	"Wheat.png", 
	"SandFloorBeach.png",
	"RockSea.png",
	"RockSeaSand.png",
	"WormFloor.png", 
	"WormWall.png",
	"WormRock.png",
	"CrypticWall.png",
	"CrypticWallBot.png",
	"CrypticWallVert.png",
	"Dripping1.png",
	"Dripping2.png",
	"Dripping3.png",
	"MetalShelf.png",
	"VeinWorm1.png",
	"VeinWorm2.png",
	"VeinWorm3.png", 
	"VeinWorm4.png",
	"FactoryWall.png",
	"FactoryFloor.png", 
	"OfficeWall.png", 
	"OfficeWallPaintingA.png", 
	"OfficeWallPaintingB.png", 
	"OfficeWallPaintingC.png",
	"OfficeWallPaintingD.png",
	"OfficeWallPaintingE.png",
	"Server1.png", 
	"Server2.png", 
	"Server3.png", 
	"MachineClock.png",
	"MachinePipes.png", 
	"MachineKeyboard.png",
	"AbyssPinkArenaFloor.png",
	"AbyssPinkCollom.png",
	"AbyssPinkCollomTop.png",
	"PinkArenaWall.png",
	"PinkArenaWallTop.png",
	"PinkSymbolEye1.png",
	"PinkSymbolEye2.png",
	"PinkSymbolEye3.png",
	"PinkSymbolEye4.png",
	"Why",
	"PinkSymbolX1.png",
	"PinkSymbolX2.png",
	"PinkSymbolX3.png",
	"PinkSymbolX4.png",
	"are",
	"PinkSymbolSpiral1.png",
	"PinkSymbolSpiral2.png",
	"PinkSymbolSpiral3.png",
	"PinkSymbolSpiral4.png",
	"you",
	"PinkSymbolFel1.png",
	"PinkSymbolFel2.png",
	"PinkSymbolFel3.png",
	"PinkSymbolFel4.png",
	"here",
	"PinkSymbolDown1.png",
	"PinkSymbolDown2.png",
	"PinkSymbolDown3.png",
	"PinkSymbolDown4.png",
	"questionMark",
	"PinkSymbolFall1.png",
	"PinkSymbolFall2.png",
	"PinkSymbolFall3.png",
	"PinkSymbolFall4.png",
	"happy.png",
	"",
	"",
	"CaveCultSymbolPurple.png",
	"CaveCultSymbols.png",
	"CaveFloor.png",
	"CaveWall.png",
	"Cornfield.png",
	"CornfieldBottom.png",
	"CornfieldTop.png",
	"CultPentBL.png",
	"CultPentBR.png",
	"CultPentTL.png",
	"CultPentTR.png",
	"GrayBrickHole.png",
	"HagHouseLogs.png",
	"HagHouseLogsEnd.png",
	"HagHouseLogsLeft.png",
	"HagHouseLogsRight.png",
	"HagHouseWindow.png",
	"HauntedForestDarkness1.png",
	"HauntedForestDarkness2.png",
	"HauntedForestDarkness3.png",
	"HauntedForestDarkness4.png",
	"HauntedForestDarkness5.png",
	"HauntedForestDarkness6.png",
	"HauntedForestDarkness7.png",
	"HauntedForestDarknessEyesStatic.png",
	"HauntedForestDarknessStatic.png",
	"HauntedForestDirt.png",
	"HauntedForestGrass.png",
	"HauntedForestLeaves.png",
	"HauntedForestPillar.png",
	"HauntedForestPillarBottom.png",
	"HauntedForestPillarBottomTrees.png",
	"HauntedForestPillarTop.png",
	"HauntedForestPillarTopTreespng.png",
	"HauntedForestRock.png",
	"HauntedForestTreeGap1.png",
	"HauntedForestTreeGap2.png",
	"HauntedForestTreeGap3.png",
	"HauntedForestTreeGap4.png",
	"HauntedForestTreeGap5.png",
	"HauntedForestTreeGap6.png",
	"HauntedForestTreeGap7.png",
	"HauntedForestTreeGapEyesStatic.png",
	"HauntedForestTreeGapStatic.png",
	"HauntedForestTrees1.png",
	"HauntedForestTrees2.png",
	"HauntedForestTrees3.png",
	"HauntedForestTrees4.png",
	"HauntedForestTrees5.png",
	"HauntedForestTrees6.png",
	"HauntedForestTrees7.png",
	"HauntedForestTreesAlt1.png",
	"HauntedForestTreesAlt2.png",
	"HauntedForestTreesAlt3.png",
	"HauntedForestTreesAlt4.png",
	"HauntedForestTreesAlt5.png",
	"HauntedForestTreesAlt6.png",
	"HauntedForestTreesAlt7.png",
	"HauntedForestTreesAltEyesStatic.png",
	"HauntedForestTreesAltStatic.png",
	"HauntedForestTreesEyesStatic.png",
	"HauntedForestTreesStatic.png",
	"HauntedForestTreeTopGap.png",
	"HauntedForestTreeTops.png",
	"HauntedForestTreeTopsAlt.png",
	"HauntedForestTreeTrunk.png",
	"HFDirtGrassE.png",
	"HFDirtGrassN.png",
	"HFDirtGrassNE.png",
	"HFDirtGrassNW.png",
	"HFDirtGrassS.png",
	"HFDirtGrassSE.png",
	"HFDirtGrassSW.png",
	"HFDirtGrassW.png",
	"HFPuzzlePillarDark.png",
	"HFPuzzlePillarLight.png",
	"HTDirtRockE.png",
	"HTDirtRockN.png",
	"HTDirtRockNE.png",
	"HTDirtRockNW.png",
	"HTDirtRockS.png",
	"HTDirtRockSE.png",
	"HTDirtRockSW.png",
	"HTDirtRockW.png",
	"BioluminescentDirt.png",
	"BioluminescentDirt2png.png",
	"BioluminescentGrass.png",
	"DirtBioGrassBLeft.png",
	"DirtBioGrassBRight.png",
	"DirtBioGrassE.png",
	"DirtBioGrassN.png",
	"DirtBioGrassS.png",
	"DirtBioGrassTLeft.png",
	"DirtBioGrassTRight.png",
	"DirtBioGrassW.png",
	"DirtRockBLeft.png",
	"DirtRockBRight.png",
	"DirtRockE.png",
	"DirtRockN.png",
	"DirtRockS.png",
	"DirtRockTLeft.png",
	"DirtRockTRight.png",
	"DirtRockW.png",
	"Tunnels1Dirt.png",
	"TunnelsDirtBLeft.png",
	"TunnelsDirtBRight.png",
	"TunnelsDirtTLeft.png",
	"TunnelsDirtTRight.png",
	"TunnelsRock.png",
};

int canWearEquip(Entity* entity, int category)
{
	Stat* stats;
	int equipType = 0;
	int type;
	if ( entity != NULL )
	{
		stats = entity->getStats();
		if ( stats != NULL )
		{
			type = stats->type;

			switch ( type )
			{
				//monsters that don't wear equipment (only rings/amulets)
				case DEVIL:
				case SPIDER:
				case TROLL:
				case RAT:
				case SLIME:
				case SCORPION:
				case MINOTAUR:
				case GHOUL:
				case SCARAB:
				case CRYSTALGOLEM:
				case COCKATRICE:
				case COCKROACH:
				case GARGOYLE:
				case MATILDA:
				case YETI:
				case EYEBALL:
				case ABOMINATION:
				case ANT:
				case PARASITE:
				case FROGMAN:
				case BIGWOG:
				case WEREWOLF:
				case GREY_WEREWOLF:
				case CROW:
				case ENT:
				case JACK_O_LANTERN:
				case FLESH_GOLEM:
					equipType = 0;
					break;

				//monsters with weapons only (incl. spellbooks)
				case LICH:
				case CREATURE_IMP:
				case DEMON:
				case CRYORUNE:
				case ICEDEMON:
				case METALLICBEAST:
				case SKU_LIT:
				case RAN_GIC:
				case WAN_RIT:
				case BANSHEE:
				case WILL_O_THE_WISP:
				case MR_SCARECROW:
				case GINEVRA:
				case GRETTA:
				case GRIMELDA:
				case CULTIST:
					equipType = 1;
					break;

				//monsters with cloak/weapon/shield/boots/mask/gloves (no helm)
				case GNOME:
				case INCUBUS:
				case SUCCUBUS:
				case LICH_FIRE:
				case LICH_ICE:
				case FLESHLING:
				case LICH_FALLEN:
				case DUSTDEVIL:
				case CLONE_FALLEN:
					equipType = 2;
					break;

				//monsters with cloak/weapon/shield/boots/helm/armor/mask/gloves
				case GOBLIN:
				case HUMAN:
				case VAMPIRE:
				case SKELETON:
				case SHOPKEEPER:
				case SHADOW:
				case AUTOMATON:
				case GOATMAN:
				case KOBOLD:
				case INSECTOID:
				case BURGGUARD:
				case CHOLOROSH:
					equipType = 3;
					break;

				default:
					equipType = 0;
					break;
			}
		}
	}

	if ( category == 0 && equipType >= 3 ) //HELM
	{
		return 1;
	}
	else if ( category == 1 && equipType >= 1 ) //WEAPON
	{
		return 1;
	}
	else if ( category == 2 && equipType >= 2 ) //SHIELD
	{
		return 1;
	}
	else if ( category == 3 && equipType >= 3 ) //ARMOR
	{
		return 1;
	}
	else if ( category == 4 && equipType >= 2 ) //BOOTS
	{
		return 1;
	}
	else if ( category == 5 || category == 6 )  //RINGS/AMULETS WORN BY ALL
	{
		return 1;
	}
	else if ( (category >= 7 && category <= 9) && equipType >= 2 ) //CLOAK/MASK/GLOVES
	{
		return 1;
	}
	else
	{
		return 0;
	}

	return 0;
}

void setSpriteAttributes(Entity* entityNew, Entity* entityToCopy, Entity* entityStatToCopy)
{
	Stat* tmpStats = nullptr;
	if ( !entityNew )
	{
		return;
	}

	if ( entityStatToCopy != nullptr )
	{
		tmpStats = entityStatToCopy->getStats();
	}

	int spriteType = checkSpriteType(entityNew->sprite);
	// monsters.
	if ( spriteType == 1 )
	{
		//STAT ASSIGNMENT
		Stat* myStats = nullptr;
		if ( multiplayer != CLIENT )
		{
			// need to give the entity its list stuff.
			// create an empty first node for traversal purposes
			node_t* node2 = list_AddNodeFirst(&entityNew->children);
			node2->element = nullptr;
			node2->deconstructor = &emptyDeconstructor;

			node2 = list_AddNodeLast(&entityNew->children);
			if ( tmpStats != nullptr )
			{
				node2->element = tmpStats->copyStats();
				node2->size = sizeof(tmpStats);
			}
			else
			{
				// if the previous sprite did not have stats initialised, or creating a new entity.
				myStats = new Stat(entityNew->sprite);
				node2->element = myStats;
				node2->size = sizeof(myStats);
			}
			//					node2->deconstructor = &myStats->~Stat;
		}
	}
	// chests.
	else if ( spriteType == 2 )
	{
		if ( entityToCopy != nullptr )
		{
			// copy old entity attributes to newly created.
			entityNew->yaw = entityToCopy->yaw;
			entityNew->skill[9] = entityToCopy->skill[9];
			entityNew->chestLocked = entityToCopy->chestLocked;
		}
		else
		{
			// set default new entity attributes.
			entityNew->yaw = 1;
			entityNew->skill[9] = 0;
			entityNew->chestLocked = -1;
		}
	}
	// items.
	else if ( spriteType == 3 )
	{
		if ( entityToCopy != nullptr )
		{
			// copy old entity attributes to newly created.
			entityNew->skill[10] = entityToCopy->skill[10];
			entityNew->skill[11] = entityToCopy->skill[11];
			entityNew->skill[12] = entityToCopy->skill[12];
			entityNew->skill[13] = entityToCopy->skill[13];
			entityNew->skill[15] = entityToCopy->skill[15];
			entityNew->skill[16] = entityToCopy->skill[16];
		}
		else
		{
			// set default new entity attributes.
			entityNew->skill[10] = 1;
			entityNew->skill[11] = 0;
			entityNew->skill[12] = 10;
			entityNew->skill[13] = 1;
			entityNew->skill[15] = 0;
			entityNew->skill[16] = 0;
		}
	}
	// summoning trap.
	else if ( spriteType == 4 )
	{
		if ( entityToCopy != nullptr )
		{
			// copy old entity attributes to newly created.
			entityNew->skill[0] = entityToCopy->skill[0];
			entityNew->skill[1] = entityToCopy->skill[1];
			entityNew->skill[2] = entityToCopy->skill[2];
			entityNew->skill[3] = entityToCopy->skill[3];
			entityNew->skill[4] = entityToCopy->skill[4];
			entityNew->skill[5] = entityToCopy->skill[5];
		}
		else
		{
			// set default new entity attributes.
			entityNew->skill[0] = 0;
			entityNew->skill[1] = 1;
			entityNew->skill[2] = 1;
			entityNew->skill[3] = 1;
			entityNew->skill[4] = 0;
			entityNew->skill[5] = 0;
		}
	}
	// power crystal
	else if ( spriteType == 5 )
	{
		if ( entityToCopy != nullptr )
		{
			// copy old entity attributes to newly created.
			entityNew->yaw = entityToCopy->yaw;
			entityNew->crystalNumElectricityNodes = entityToCopy->crystalNumElectricityNodes;
			entityNew->crystalTurnReverse = entityToCopy->crystalTurnReverse;
			entityNew->crystalSpellToActivate = entityToCopy->crystalSpellToActivate;
		}
		else
		{
			// set default new entity attributes.
			entityNew->yaw = 0;
			entityNew->crystalNumElectricityNodes = 5;
			entityNew->crystalTurnReverse = 0;
			entityNew->crystalSpellToActivate = 0;
		}
	}
	// lever timer
	else if ( spriteType == 6 )
	{
		if ( entityToCopy != nullptr )
		{
			// copy old entity attributes to newly created.
			entityNew->leverTimerTicks = entityToCopy->leverTimerTicks;
		}
		else
		{
			// set default new entity attributes.
			entityNew->leverTimerTicks = 3;
		}
	}
	// boulder trap with re-fire
	else if ( spriteType == 7 )
	{
		if ( entityToCopy != nullptr )
		{
			// copy old entity attributes to newly created.
			entityNew->boulderTrapRefireDelay = entityToCopy->boulderTrapRefireDelay;
			entityNew->boulderTrapRefireAmount = entityToCopy->boulderTrapRefireAmount;
			entityNew->boulderTrapPreDelay = entityToCopy->boulderTrapPreDelay;
		}
		else
		{
			// set default new entity attributes.
			entityNew->boulderTrapRefireDelay = 3;
			entityNew->boulderTrapRefireAmount = 0;
			entityNew->boulderTrapPreDelay = 0;
		}
	}
	// pedestal
	else if ( spriteType == 8 )
	{
		if ( entityToCopy != nullptr )
		{
			// copy old entity attributes to newly created.
			entityNew->pedestalOrbType = entityToCopy->pedestalOrbType;
			entityNew->pedestalHasOrb = entityToCopy->pedestalHasOrb;
			entityNew->pedestalInvertedPower = entityToCopy->pedestalInvertedPower;
			entityNew->pedestalInGround = entityToCopy->pedestalInGround;
			entityNew->pedestalLockOrb = entityToCopy->pedestalLockOrb;
		}
		else
		{
			// set default new entity attributes.
			entityNew->pedestalOrbType = 0;
			entityNew->pedestalHasOrb = 0;
			entityNew->pedestalInvertedPower = 0;
			entityNew->pedestalInGround = 0;
			entityNew->pedestalLockOrb = 0;
		}
	}
	// teleporter
	else if ( spriteType == 9 )
	{
		if ( entityToCopy != nullptr )
		{
			// copy old entity attributes to newly created.
			entityNew->teleporterX = entityToCopy->teleporterX;
			entityNew->teleporterY = entityToCopy->teleporterY;
			entityNew->teleporterType = entityToCopy->teleporterType;
		}
		else
		{
			// set default new entity attributes.
			entityNew->teleporterX = 1;
			entityNew->teleporterY = 1;
			entityNew->teleporterType = 0;
		}
	}
	// ceiling tile
	else if ( spriteType == 10 )
	{
		if ( entityToCopy != nullptr )
		{
			// copy old entity attributes to newly created.
			entityNew->ceilingTileModel = entityToCopy->ceilingTileModel;
		}
		else
		{
			// set default new entity attributes.
			entityNew->ceilingTileModel = 0;
		}
	}
	// spell trap
	else if ( spriteType == 11 )
	{
		if ( entityToCopy != nullptr )
		{
			// copy old entity attributes to newly created.
			entityNew->spellTrapType = entityToCopy->spellTrapType;
			entityNew->spellTrapRefire = entityToCopy->spellTrapRefire;
			entityNew->spellTrapLatchPower = entityToCopy->spellTrapLatchPower;
			entityNew->spellTrapFloorTile = entityToCopy->spellTrapFloorTile;
			entityNew->spellTrapRefireRate = entityToCopy->spellTrapRefireRate;
		}
		else
		{
			// set default new entity attributes.
			// copy old entity attributes to newly created.
			entityNew->spellTrapType = -1;
			entityNew->spellTrapRefire = -1;
			entityNew->spellTrapLatchPower = 0;
			entityNew->spellTrapFloorTile = 0;
			entityNew->spellTrapRefireRate = 1;
		}
	}
	// furniture
	else if ( spriteType == 12 )
	{
		if ( entityToCopy != nullptr )
		{
			// copy old entity attributes to newly created.
			entityNew->furnitureDir = entityToCopy->furnitureDir;
		}
		else
		{
			// set default new entity attributes.
			if ( entityNew->sprite == 60 ) // chair
			{
				entityNew->furnitureDir = -1;
			}
			else
			{
				entityNew->furnitureDir = 0;
			}
		}
	}
	// floor decoration
	else if ( spriteType == 13 )
	{
		if ( entityToCopy != nullptr )
		{
			// copy old entity attributes to newly created.
			entityNew->floorDecorationModel = entityToCopy->floorDecorationModel;
			entityNew->floorDecorationRotation = entityToCopy->floorDecorationRotation;
			entityNew->floorDecorationHeightOffset = entityToCopy->floorDecorationHeightOffset;
			entityNew->floorDecorationXOffset = entityToCopy->floorDecorationXOffset;
			entityNew->floorDecorationYOffset = entityToCopy->floorDecorationYOffset;
			for ( int i = 8; i < 60; ++i )
			{
				entityNew->skill[i] = entityToCopy->skill[i];
			}
		}
		else
		{
			// set default new entity attributes.
			entityNew->floorDecorationModel = 0;
			entityNew->floorDecorationRotation = 0;
			entityNew->floorDecorationHeightOffset = 0;
			entityNew->floorDecorationXOffset = 0;
			entityNew->floorDecorationYOffset = 0;
			for ( int i = 8; i < 60; ++i )
			{
				entityNew->skill[i] = 0;
			}
		}
	}
	else if ( spriteType == 14 )
	{
		if ( entityToCopy != nullptr )
		{
			// copy old entity attributes to newly created.
			entityNew->soundSourceToPlay = entityToCopy->soundSourceToPlay;
			entityNew->soundSourceVolume = entityToCopy->soundSourceVolume;
			entityNew->soundSourceLatchOn = entityToCopy->soundSourceLatchOn;
			entityNew->soundSourceDelay = entityToCopy->soundSourceDelay;
			entityNew->soundSourceOrigin = entityToCopy->soundSourceOrigin;
		}
		else
		{
			// set default new entity attributes.
			entityNew->soundSourceToPlay = 0;
			entityNew->soundSourceVolume = 0;
			entityNew->soundSourceLatchOn = 0;
			entityNew->soundSourceDelay = 0;
			entityNew->soundSourceOrigin = 0;
		}
	}
	else if ( spriteType == 15 )
	{
		if ( entityToCopy != nullptr )
		{
			// copy old entity attributes to newly created.
			entityNew->lightSourceAlwaysOn = entityToCopy->lightSourceAlwaysOn;
			entityNew->lightSourceBrightness = entityToCopy->lightSourceBrightness;
			entityNew->lightSourceInvertPower = entityToCopy->lightSourceInvertPower;
			entityNew->lightSourceLatchOn = entityToCopy->lightSourceLatchOn;
			entityNew->lightSourceRadius = entityToCopy->lightSourceRadius;
			entityNew->lightSourceFlicker = entityToCopy->lightSourceFlicker;
			entityNew->lightSourceDelay = entityToCopy->lightSourceDelay;
		}
		else
		{
			// set default new entity attributes.
			entityNew->lightSourceAlwaysOn = 0;
			entityNew->lightSourceBrightness = 128;
			entityNew->lightSourceInvertPower = 0;
			entityNew->lightSourceLatchOn = 0;
			entityNew->lightSourceRadius = 5;
			entityNew->lightSourceFlicker = 0;
			entityNew->lightSourceDelay = 0;
		}
	}
	else if ( spriteType == 16 )
	{
		if ( entityToCopy != nullptr )
		{
			// copy old entity attributes to newly created.
			entityNew->textSourceColorRGB = entityToCopy->textSourceColorRGB;
			entityNew->textSourceVariables4W = entityToCopy->textSourceVariables4W;
			entityNew->textSourceDelay = entityToCopy->textSourceDelay;
			entityNew->textSourceIsScript = entityToCopy->textSourceIsScript;
			for ( int i = 4; i < 60; ++i )
			{
				entityNew->skill[i] = entityToCopy->skill[i];
			}
		}
		else
		{
			// set default new entity attributes.
			entityNew->textSourceColorRGB = 0xFFFFFFFF;
			entityNew->textSourceVariables4W = 0;
			entityNew->textSourceDelay = 0;
			entityNew->textSourceIsScript = 0;
			for ( int i = 4; i < 60; ++i )
			{
				entityNew->skill[i] = 0;
			}
		}
	}
	else if ( spriteType == 17 )
	{
		if ( entityToCopy != nullptr )
		{
			// copy old entity attributes to newly created.
			entityNew->signalInputDirection = entityToCopy->signalInputDirection;
			entityNew->signalActivateDelay = entityToCopy->signalActivateDelay;
			entityNew->signalTimerInterval = entityToCopy->signalTimerInterval;
			entityNew->signalTimerRepeatCount = entityToCopy->signalTimerRepeatCount;
			entityNew->signalTimerLatchInput = entityToCopy->signalTimerLatchInput;
		}
		else
		{
			// set default new entity attributes.
			entityNew->signalInputDirection = 0;
			entityNew->signalActivateDelay = 0;
			entityNew->signalTimerInterval = 0;
			entityNew->signalTimerRepeatCount = 0;
			entityNew->signalTimerLatchInput = 0;
		}
	}
	else if ( spriteType == 18 )
	{
		if ( entityToCopy != nullptr )
		{
			// copy old entity attributes to newly created.
			entityNew->portalCustomSprite = entityToCopy->portalCustomSprite;
			entityNew->portalCustomSpriteAnimationFrames = entityToCopy->portalCustomSpriteAnimationFrames;
			entityNew->portalCustomZOffset = entityToCopy->portalCustomZOffset;
			entityNew->portalCustomLevelsToJump = entityToCopy->portalCustomLevelsToJump;
			entityNew->portalNotSecret = entityToCopy->portalNotSecret;
			entityNew->portalCustomRequiresPower = entityToCopy->portalCustomRequiresPower;
			for ( int i = 11; i <= 18; ++i )
			{
				entityNew->skill[i] = entityToCopy->skill[i];
			}
		}
		else
		{
			// set default new entity attributes.
			entityNew->portalCustomSprite = 161;
			entityNew->portalCustomSpriteAnimationFrames = 0;
			entityNew->portalCustomZOffset = 8;
			entityNew->portalCustomLevelsToJump = 1;
			entityNew->portalNotSecret = 1;
			entityNew->portalCustomRequiresPower = 0;
			for ( int i = 11; i <= 18; ++i )
			{
				entityNew->skill[i] = 0;
			}
		}
	}
	else if ( spriteType == 19 ) // tables
	{
		if ( entityToCopy != nullptr )
		{
			// copy old entity attributes to newly created.
			entityNew->furnitureDir = entityToCopy->furnitureDir;
			entityNew->furnitureTableSpawnChairs = entityToCopy->furnitureTableSpawnChairs;
			entityNew->furnitureTableRandomItemChance = entityToCopy->furnitureTableRandomItemChance;
		}
		else
		{
			// set default new entity attributes.
			entityNew->furnitureDir = -1;
			entityNew->furnitureTableSpawnChairs = -1;
			entityNew->furnitureTableRandomItemChance = -1;
		}
	}
	else if ( spriteType == 20 ) // readable book
	{
		if ( entityToCopy != nullptr )
		{
			// copy old entity attributes to newly created.
			entityNew->skill[11] = entityToCopy->skill[11];
			entityNew->skill[12] = entityToCopy->skill[12];
			entityNew->skill[15] = entityToCopy->skill[15];
			for ( int i = 40; i <= 52; ++i )
			{
				entityNew->skill[i] = entityToCopy->skill[i];
			}
		}
		else
		{
			// set default new entity attributes.
			entityNew->skill[11] = 0;
			entityNew->skill[12] = 10;
			entityNew->skill[15] = 0;
			for ( int i = 40; i <= 52; ++i )
			{
				entityNew->skill[i] = 0;
			}
		}
	}
	else if ( spriteType == 21 ) // doors
	{
		if ( entityToCopy != nullptr )
		{
			// copy old entity attributes to newly created.
			entityNew->doorForceLockedUnlocked = entityToCopy->doorForceLockedUnlocked;
			entityNew->doorDisableLockpicks = entityToCopy->doorDisableLockpicks;
			entityNew->doorDisableOpening= entityToCopy->doorDisableOpening;
		}
		else
		{
			// set default new entity attributes.
			entityNew->doorForceLockedUnlocked = 0;
			entityNew->doorDisableLockpicks = 0;
			entityNew->doorDisableOpening = 0;
		}
	}
	else if ( spriteType == 22 ) // gates
	{
		if ( entityToCopy != nullptr )
		{
			// copy old entity attributes to newly created.
			entityNew->gateDisableOpening = entityToCopy->gateDisableOpening;
		}
		else
		{
			// set default new entity attributes.
			entityNew->gateDisableOpening = 0;
		}
	}
	else if ( spriteType == 23 ) // player spawns
	{
		if ( entityToCopy != nullptr )
		{
			// copy old entity attributes to newly created.
			entityNew->playerStartDir = entityToCopy->playerStartDir;
		}
		else
		{
			// set default new entity attributes.
			entityNew->playerStartDir = 0;
		}
	}

	if ( entityToCopy != nullptr )
	{
		// if we are duplicating sprite, then copy the x and y coordinates.
		entityNew->x = entityToCopy->x;
		entityNew->y = entityToCopy->y;
	}
	else
	{
		// new entity, will follow the mouse movements when created.
	}
}
