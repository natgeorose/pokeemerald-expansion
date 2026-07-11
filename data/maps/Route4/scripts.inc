.set LOCALID_DAYCARE_MON_0, 25
.set LOCALID_DAYCARE_MON_1, 26

Route4_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_OnTransition
	.byte 0

Route4_OnTransition:
	call Route4_EventScript_TryMoveDayCareMan
	@ set flags for OW daycare mons
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	getdaycaregfx VAR_OBJ_GFX_ID_0, VAR_OBJ_GFX_ID_1, VAR_TEMP_0, VAR_TEMP_1
	switch VAR_RESULT
	case 2, Route4_EventScript_ShowDaycareMon1
	case 1, Route4_EventScript_ShowDaycareMon0
	end

Route4_EventScript_ShowDaycareMon1:
	@ set pokemon movement type based on compatibility
	special SetDaycareCompatibilityString
	call_if_eq VAR_RESULT, PARENTS_INCOMPATIBLE, Route4_EventScript_DaycareMonIncompatible
	@ Don't do anything if PARENTS_LOW_COMPATIBILITY
	call_if_eq VAR_RESULT, PARENTS_MED_COMPATIBILITY, Route4_EventScript_DaycareMonMedCompatibility
	call_if_eq VAR_RESULT, PARENTS_MAX_COMPATIBILITY, Route4_EventScript_DaycareMonMaxCompatibility
	clearflag FLAG_TEMP_2
Route4_EventScript_ShowDaycareMon0:
	clearflag FLAG_TEMP_1
	end

Route4_EventScript_DaycareMonIncompatible: @ mons never face each other
	setobjectmovementtype LOCALID_DAYCARE_MON_0, MOVEMENT_TYPE_FACE_DOWN_UP_AND_LEFT
	setobjectmovementtype LOCALID_DAYCARE_MON_1, MOVEMENT_TYPE_FACE_DOWN_UP_AND_RIGHT
	return

Route4_EventScript_DaycareMonMedCompatibility: @ down and towards each other
	setobjectmovementtype LOCALID_DAYCARE_MON_0, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_DAYCARE_MON_1, MOVEMENT_TYPE_FACE_DOWN_AND_LEFT
	return

Route4_EventScript_DaycareMonMaxCompatibility: @ facing; walk in place
	setobjectmovementtype LOCALID_DAYCARE_MON_0, MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT
	setobjectmovementtype LOCALID_DAYCARE_MON_1, MOVEMENT_TYPE_WALK_IN_PLACE_LEFT
	return

Route4_EventScript_TryMoveDayCareMan::
	goto_if_unset FLAG_PENDING_DAYCARE_EGG, Route4_EventScript_StopMoveDayCareMan
	setobjectxyperm LOCALID_DAYCARE_MAN, 26, 11
Route4_EventScript_StopMoveDayCareMan::
	return

Speaker_Kolby:
    .string "Kolby$"

Route4_EventScript_Kolby::
	trainerbattle_single TRAINER_KOLBY, Route4_Text_KolbyIntro, Route4_Text_KolbyDefeat
	setspeaker Speaker_Kolby
	msgbox Route4_Text_KolbyPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Ariel:
    .string "Ariel$"

Route4_EventScript_Ariel::
	trainerbattle_single TRAINER_ARIEL, Route4_Text_ArielIntro, Route4_Text_ArielDefeat
	setspeaker Speaker_Ariel
	msgbox Route4_Text_ArielPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Viola:
    .string "Viola$"

Route4_EventScript_Viola::
	trainerbattle_single TRAINER_VIOLA, Route4_Text_ViolaIntro, Route4_Text_ViolaDefeat
	setspeaker Speaker_Viola
	msgbox Route4_Text_ViolaPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Calvin:
    .string "Calvin$"

Route4_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, Route4_Text_CalvinIntro, Route4_Text_CalvinDefeat
	setspeaker Speaker_Calvin
	msgbox Route4_Text_CalvinPostBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Elder::
	lockall
	setspeaker Speaker_Elder
	msgbox Route4_Text_Elder, MSGBOX_NPC
	releaseall
	end

Route4_Text_Elder:
	.string "You came here from Erewood Grove?\p"
	.string "Well I can promise you Route 4 is\n"
	.string "much more pleasant.$"

Route4_EventScript_Maniac::
	lockall
	setspeaker Speaker_Scientist
	msgbox Route4_Text_Maniac, MSGBOX_NPC
	releaseall
	end

Route4_Text_Maniac:
	.string "As a Trainer it would serve you well\n"
	.string "to learn about breeding.\p"
	.string "Natures, traits, and even moves can\n"
	.string "be inherited,\l"
	.string "if you know what you are doing.$"

Route4_EventScript_Woman::
	lockall
	faceplayer
	call_if_set FLAG_MET_WOMAN_ROUTE4, Route4_EventScript_WomanTwo
	setspeaker Speaker_Woman
	msgbox Route4_Text_WomanIntro, MSGBOX_NPC
	closemessage
	setflag FLAG_MET_WOMAN_ROUTE4
	releaseall
	end

Route4_EventScript_WomanTwo::
	lockall
	faceplayer
	call_if_defeated TRAINER_KOLBY, Route4_EventScript_KolbyDefeated
	call_if_defeated TRAINER_ARIEL, Route4_EventScript_ArielDefeated
	setspeaker Speaker_Woman
	msgbox Route4_Text_WomanNone, MSGBOX_NPC
	closemessage
	releaseall
	end;

Route4_EventScript_KolbyDefeated::
	call_if_defeated TRAINER_ARIEL, Route4_EventScript_WomanBoth
	setspeaker Speaker_Woman
	msgbox Route4_Text_WomanOne, MSGBOX_NPC
	closemessage
	releaseall
	end

Route4_EventScript_ArielDefeated::
	call_if_defeated TRAINER_KOLBY, Route4_EventScript_WomanBoth
	setspeaker Speaker_Woman
	msgbox Route4_Text_WomanOne, MSGBOX_NPC
	closemessage
	releaseall
	end

Route4_EventScript_WomanBoth::
	call_if_set FLAG_RECEIVED_SOOTHE_BELL, Route4_EventScript_WomanPost
	setspeaker Speaker_Woman
	msgbox Route4_Text_WomanGiveSootheBell, MSGBOX_NPC
	closemessage
	giveitem ITEM_SOOTHE_BELL
	setflag FLAG_RECEIVED_SOOTHE_BELL
	releaseall
	end

Route4_EventScript_WomanPost::
	setspeaker Speaker_Woman
	msgbox Route4_Text_WomanPost, MSGBOX_NPC
	closemessage
	releaseall
	end

Route4_Text_WomanIntro:
	.string "Kolby! Ariel! Please come back!\p"
	.string "...\p"
	.string "Oh what am I to do? I gave my kids\n"
	.string "their first Pokémon,\l"
	.string "and now they won't listen to me!\p"
	.string "You there, please help me! Maybe if\n"
	.string "you defeat them in a battle they\p"
	.string "will come back to me. I promise to\n"
	.string "make it worth your while.$"

Route4_Text_WomanNone:
	.string "Please help me with my children!$"

Route4_Text_WomanOne:
	.string "Thank you, just one more to go!$"

Route4_Text_WomanPost:
	.string "Thank you so much for your help!$"

Route4_Text_WomanGiveSootheBell:
	.string "You've defeated both my kids?\n"
	.string "Thank you for helping me!\p"
	.string "Hopefully they have calmed down and\n"
	.string "will listen to me now.\p"
	.string "As promised, please take this Soothe\n"
	.string "Bell. If it can't calm down my kids,\l"
	.string "hopefully it can soothe your Pokémon.$"

Route4_EventScript_RouteSign::
	msgbox Route4_Text_RouteSign, MSGBOX_SIGN
	end

Route4_Text_RouteSign:
	.string "Route 4\p"
	.string "{LEFT_ARROW} Quilspring Town\n"
	.string "{RIGHT_ARROW} Erewood Grove$"


