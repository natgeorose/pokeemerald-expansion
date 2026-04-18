SundaraVillage_House1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SundaraVillage_House1_OnLoad
	.byte 0

SundaraVillage_House1_OnLoad:
	call_if_eq VAR_SUNDARA_QUEST, 2, SundaraVillage_House1_EventScript_HideFrillish
	call_if_eq VAR_SUNDARA_QUEST, 3, SundaraVillage_House1_EventScript_HideHorsea
	call_if_eq VAR_SUNDARA_QUEST, 4, SundaraVillage_House1_EventScript_HideStaryu
	end

SundaraVillage_House1_EventScript_HideFrillish::
	setflag FLAG_TEMP_10
	return

SundaraVillage_House1_EventScript_HideHorsea::
	setflag FLAG_TEMP_11
	return

SundaraVillage_House1_EventScript_HideStaryu::
	setflag FLAG_TEMP_12
	return

SundaraVillage_House1_EventScript_Man::
	lockall
	faceplayer
	switch VAR_SUNDARA_QUEST
	case 0, SundaraVillage_House1_EventScript_ManIntro
	case 1, SundaraVillage_House1_EventScript_ManSigh
	case 2, SundaraVillage_House1_EventScript_ManFrillish
	case 3, SundaraVillage_House1_EventScript_ManHorsea
	case 4, SundaraVillage_House1_EventScript_ManStaryu
	end

SundaraVillage_House1_EventScript_ManIntro::
	setspeaker Speaker_Researcher
	msgbox SundaraVillage_House1_Text_ManIntro, MSGBOX_NPC
	closemessage
	setvar VAR_SUNDARA_QUEST, 1
	goto_if_set FLAG_HIDDEN_ITEM_ROUTE_6_ARTIFACT, SundaraVillage_House1_EventScript_ManGiveMon
	releaseall
	end

SundaraVillage_House1_Text_ManIntro:
	.string "Ah I can't believe it!\n"
	.string "How could I be so careless?!\p"
	.string "Oh sorry, I didn't mean to startle\n"
	.string "you. I'm just so upset at myself!\p"
	.string "I was on an expedition to find some\n"
	.string "rare fossils on Route 6, and I lost\l"
	.string "my most prized possession!\p"
	.string "It's a rare artifact that I found\n"
	.string "when I was still studying to become\l"
	.string "a Researcher, it means the world to me!\p"
	.string "I was ready for long day of research,\n"
	.string "I even brought all of these Water\l"
	.string "Pokémon to keep me cool in the heat.\p"
	.string "I'm too sad now to even think of\n"
	.string "going out and working, it's too much.\p"
	.string "If you find the artifact I would be\n"
	.string "forever grateful, but I don't have\l"
	.string "high hopes... Sigh...$"

SundaraVillage_House1_EventScript_ManSigh::
	setspeaker Speaker_Researcher
	msgbox SundaraVillage_House1_Text_ManSigh, MSGBOX_NPC
	closemessage
	goto_if_set FLAG_HIDDEN_ITEM_ROUTE_6_ARTIFACT, SundaraVillage_House1_EventScript_ManGiveMon
	releaseall
	end

SundaraVillage_House1_Text_ManSigh:
	.string "If you find the artifact I would be\n"
	.string "forever grateful, but I don't have\l"
	.string "high hopes... Sigh...$"

Speaker_Frillish:
    .string "Frillish$"

Speaker_Horsea:
    .string "Horsea$"

Speaker_Staryu:
    .string "Staryu$"

SundaraVillage_House1_EventScript_ManGiveMon::
	setspeaker Speaker_Researcher
	msgbox SundaraVillage_House1_Text_ManThanks, MSGBOX_NPC
	closemessage
	removeitem ITEM_TEA
	dynmultipush Speaker_Frillish, 0
	dynmultipush Speaker_Horsea, 1
	dynmultipush Speaker_Staryu, 2
	dynmultistack 0, 0, TRUE, 3, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, SundaraVillage_House1_EventScript_PickedFrillish
	case 1, SundaraVillage_House1_EventScript_PickedHorsea
	case 2, SundaraVillage_House1_EventScript_PickedStaryu
	releaseall
	end

SundaraVillage_House1_EventScript_PickedFrillish::
	setvar VAR_SUNDARA_QUEST, 2
	givemon SPECIES_FRILLISH, 15
	removeobject LOCALID_FRILLISH
	msgbox SundaraVillage_House1_Text_TakeFrillish, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_TEMP_10
	releaseall
	end

SundaraVillage_House1_EventScript_PickedHorsea::
	setvar VAR_SUNDARA_QUEST, 3
	givemon SPECIES_HORSEA, 15
	removeobject LOCALID_HORSEA
	msgbox SundaraVillage_House1_Text_TakeHorsea, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_TEMP_11
	releaseall
	end
	
SundaraVillage_House1_EventScript_PickedStaryu::
	setvar VAR_SUNDARA_QUEST, 4
	givemon SPECIES_STARYU, 15
	removeobject LOCALID_STARYU
	msgbox SundaraVillage_House1_Text_TakeStaryu, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_TEMP_12
	releaseall
	end

SundaraVillage_House1_Text_TakeFrillish:
	.string "{PLAYER} received a Frillish!$"

SundaraVillage_House1_Text_TakeHorsea:
	.string "{PLAYER} received a Horsea!$"

SundaraVillage_House1_Text_TakeStaryu:
	.string "{PLAYER} received a Staryu!$"

SundaraVillage_House1_Text_ManThanks:
	.string "Huh? What's that?\n"
	.string "Could it be??\p"
	.string "It is! You find my artifact! I\n"
	.string "cannot thank you enough!\p"
	.string "Speaking of, there must be something\n"
	.string "around here that I can give you as a\l"
	.string "reward for helping me...\p"
	.string "Oh I know! Why don't you have one of\n"
	.string "the Water Pokémon I have here?\p"
	.string "I certainly don't need all three to\n"
	.string "keep me cool as I'm researching!\l"
	.string "Which one will you take?$"

SundaraVillage_House1_EventScript_ManFrillish:
	lockall
	setspeaker Speaker_Researcher
	msgbox SundaraVillage_House1_Text_LikeFrillish, MSGBOX_NPC
	closemessage
	releaseall
	end	

SundaraVillage_House1_Text_LikeFrillish:
	.string "Take good care of Frillish!$"

SundaraVillage_House1_EventScript_ManHorsea:
	lockall
	setspeaker Speaker_Researcher
	msgbox SundaraVillage_House1_Text_LikeHorsea, MSGBOX_NPC
	closemessage	
	releaseall
	end

SundaraVillage_House1_Text_LikeHorsea:
	.string "Take good care of Horsea!$"

SundaraVillage_House1_EventScript_ManStaryu:
	lockall
	setspeaker Speaker_Researcher
	msgbox SundaraVillage_House1_Text_LikeStaryu, MSGBOX_NPC
	closemessage	
	releaseall
	end

SundaraVillage_House1_Text_LikeStaryu:
	.string "Take good care of Staryu!$"

SundaraVillage_House1_EventScript_Frillish::
	lockall
	playmoncry SPECIES_FRILLISH, CRY_MODE_NORMAL
	setspeaker Speaker_Frillish
	msgbox SundaraVillage_House1_Text_Frillish, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	releaseall
	end

SundaraVillage_House1_Text_Frillish:
	.string "Gyuuuu.$"

SundaraVillage_House1_EventScript_Horsea::
	lockall
	playmoncry SPECIES_HORSEA, CRY_MODE_NORMAL
	setspeaker Speaker_Horsea
	msgbox SundaraVillage_House1_Text_Horsea, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	releaseall
	end

SundaraVillage_House1_Text_Horsea:
	.string "Seeaa.$"

SundaraVillage_House1_EventScript_Staryu::
	lockall
	playmoncry SPECIES_STARYU, CRY_MODE_NORMAL
	setspeaker Speaker_Staryu
	msgbox SundaraVillage_House1_Text_Staryu, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	releaseall
	end

SundaraVillage_House1_Text_Staryu:
	.string "Buuuu.$"


