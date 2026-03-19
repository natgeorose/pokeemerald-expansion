Route5_MapScripts::
	.byte 0

Route5_EventScript_RouteSign::
	msgbox Route5_Text_RouteSign, MSGBOX_SIGN
	end

Route5_Text_RouteSign:
	.string "Route 5\n"
	.string "{DOWN_ARROW} Erewood Grove\p"
	.string "{UP_ARROW} Route 6\n"
	.string "{RIGHT_ARROW} Fellhaven Town$"

Route5_EventScript_HouseSign::
	msgbox Route5_Text_HouseSign, MSGBOX_SIGN
	end

Route5_Text_HouseSign:
	.string "Route 5\n"
	.string "Rest House$"

Route5_EventScript_PineCall::
	lockall
	setspeaker Speaker_Pine
	pokenavcall Route5_Text_PineCall
	waitmessage
	setvar VAR_STORY, 16
	releaseall
	end

Route5_Text_PineCall:
	.string "Hello? Are you there {PLAYER}?\p"
	.string "Ah there you are! I knew giving you\n"
	.string "this phone would be a good idea!\p"
	.string "James just informed me of all\n"
	.string "that occurred in Erewood Grove,\l"
	.string "I'm glad you two are okay!\p"
	.string "I think Berith and I can help shed\n"
	.string "some light on who those mysterious\l"
	.string "figures are, we must meet up!\p"
	.string "We have been researching that cave\n"
	.string "on Route 7, so meet us at the\l"
	.string "Ranger Station in Fellhaven Town.\p"
	.string "It is just east of Route 5, so it\n"
	.string "shouldn't be a far journey for you.\p"
	.string "Please get here as soon as you can!$"

Route5_EventScript_StopExplore::
	lockall
	msgbox Route5_Text_StopExplore
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	releaseall
	end

Route5_Text_StopExplore:
	.string "I should talk to Professor Pine in\n"
	.string "Fellhaven Town before going this way.$"

Route5_EventScript_OldWoman::
	lockall
	faceplayer
	switch VAR_BEEDRILL_QUEST
	case 0, Route5_EventScript_OldWomanIntro
	case 1, Route5_EventScript_OldWomanReady
	case 2, Route5_EventScript_OldWomanBattle
	case 3, Route5_EventScript_OldWomanExit
	releaseall 
	end

Route5_EventScript_OldWomanIntro::
	lockall
	faceplayer
	setvar VAR_BEEDRILL_QUEST, 1
	setspeaker Speaker_Elder
	msgbox Route5_Text_OldWomanIntro, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, YES, Route5_EventScript_OldWomanBattle
	setspeaker Speaker_Elder
	msgbox Route5_Text_OldWomanNo, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Route5_EventScript_OldWomanReady::
	lockall
	faceplayer
	setspeaker Speaker_Elder
	msgbox Route5_Text_OldWomanReady, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, YES, Route5_EventScript_OldWomanBattle
	setspeaker Speaker_Elder
	msgbox Route5_Text_OldWomanNo, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Route5_EventScript_OldWomanBattle::
	lockall
	faceplayer
	setspeaker Speaker_Elder
	msgbox Route5_Text_OldWomanBattle, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_BEEDRILL, CRY_MODE_NORMAL
	waitmoncry
	delay 15
	setwildbattle SPECIES_BEEDRILL, 22
	setflag FLAG_NO_WILD_RUN
	setflag FLAG_SMART_WILD_AI
	setflag FLAG_NO_CATCHING
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 1, 1
	dowildbattle
	clearflag FLAG_NO_WILD_RUN
	clearflag FLAG_SMART_WILD_AI
	clearflag FLAG_NO_CATCHING
	setspeaker Speaker_Elder
	msgbox Route5_Text_OldWomanWellDone, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_HEART_SCALE
	setspeaker Speaker_Elder
	msgbox Route5_Text_OldWomanSomething, MSGBOX_DEFAULT
	closemessage
	setvar VAR_BEEDRILL_QUEST, 3
	releaseall
	end

Route5_EventScript_OldWomanExit::
	lockall
	faceplayer
	setspeaker Speaker_Elder
	msgbox Route5_Text_OldWomanExit, MSGBOX_NPC
	closemessage
	releaseall
	end

Route5_Text_OldWomanIntro:
	.string "Hello there young Trainer.\n"
	.string "I'm an elder from Fellhaven Town.\p"
	.string "There have been reports of a rogue\n"
	.string "Pokémon terrorizing those passing by.\p"
	.string "I have been able to track that Pokémon\n"
	.string "here, but my attempts to calm it down\l"
	.string "have unfortunately been in vain.\p"
	.string "I need a strong Trainer to defeat this\n"
	.string "Pokémon so that I can soothe it.\p"
	.string "Be careful though, it is very powerful.\n"
	.string "Will you help me?$"

Route5_Text_OldWomanNo:
	.string "Very well then, come back whenever you\n"
	.string "are ready to face this Pokémon.$"

Route5_Text_OldWomanReady:
	.string "Are you ready to help me and battle the\n"
	.string "foe that has been terrorizing this area?$"

Route5_Text_OldWomanBattle:
	.string "Alright, get ready!$"

Route5_Text_OldWomanWellDone:
	.string "Very well done! You are quite the\n"
	.string "young Trainer. I should be able to\l"
	.string "calm this rogue Beedrill down now.\p"
	.string "Please take this as a token of my\n"
	.string "thanks for protecting this area.$"

Route5_Text_OldWomanSomething:
	.string "Oh well look at this!\p"
	.string "There is something else lying here in\n"
	.string "this Beedrill's nest!\p"
	.string "Hmm I know what this item is, but you\n"
	.string "are unable to use it currently.\p"
	.string "Come back when you are a bit stronger\n"
	.string "and I will give you this item, it is\l"
	.string "absolutely worth your time.$"

Route5_Text_OldWomanExit:
	.string "Thank you once again for your help!\p"
	.string "Come back when you are a bit stronger\n"
	.string "and I will give you this item, it is\l"
	.string "absolutely worth your time.$"

Speaker_Isadora:
    .string "Isadora$"

Route5_EventScript_Isadora::
	trainerbattle_single TRAINER_ISADORA, Route5_Text_IsadoraIntro, Route5_Text_IsadoraDefeat
	setspeaker Speaker_Isadora
	msgbox Route5_Text_IsadoraPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Eli:
    .string "Eli$"

Route5_EventScript_Eli::
	trainerbattle_single TRAINER_ELI, Route5_Text_EliIntro, Route5_Text_EliDefeat
	setspeaker Speaker_Eli
	msgbox Route5_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Jarrett:
    .string "Jarrett$"

Route5_EventScript_Jarrett::
	trainerbattle_single TRAINER_JARRETT, Route5_Text_JarrettIntro, Route5_Text_JarrettDefeat
	setspeaker Speaker_Jarrett
	msgbox Route5_Text_JarrettPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Victoria:
    .string "Victoria$"

Route5_EventScript_Victoria::
	trainerbattle_single TRAINER_VICTORIA, Route5_Text_VictoriaIntro, Route5_Text_VictoriaDefeat
	setspeaker Speaker_Victoria
	msgbox Route5_Text_VictoriaPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Dwight:
    .string "Dwight$"

Route5_EventScript_Dwight::
	trainerbattle_single TRAINER_DWIGHT, Route5_Text_DwightIntro, Route5_Text_DwightDefeat
	setspeaker Speaker_Dwight
	msgbox Route5_Text_DwightPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Drew:
    .string "Drew$"

Route5_EventScript_Drew::
	trainerbattle_single TRAINER_DREW, Route5_Text_DrewIntro, Route5_Text_DrewDefeat
	setspeaker Speaker_Drew
	msgbox Route5_Text_DrewPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Miles:
    .string "Miles$"

Route5_EventScript_Miles::
	trainerbattle_single TRAINER_MILES, Route5_Text_MilesIntro, Route5_Text_MilesDefeat
	setspeaker Speaker_Miles
	msgbox Route5_Text_MilesPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Cato:
    .string "Cato$"

Route5_EventScript_Cato::
	trainerbattle_single TRAINER_CATO, Route5_Text_CatoIntro, Route5_Text_CatoDefeat
	setspeaker Speaker_Cato
	msgbox Route5_Text_CatoPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Maynard:
    .string "Maynard$"

Route5_EventScript_Maynard::
	trainerbattle_single TRAINER_MAYNARD, Route5_Text_MaynardIntro, Route5_Text_MaynardDefeat
	setspeaker Speaker_Maynard
	msgbox Route5_Text_MaynardPostBattle, MSGBOX_AUTOCLOSE
	end

Route5_EventScript_Girl::
	setspeaker Speaker_Girl
	msgbox Route5_Text_Girl, MSGBOX_NPC
	end

Route5_Text_Girl:
	.string "This route can be hard to navigate, and\n"
	.string "it's one of the largest routes in all of\l"
	.string "the Serenado region!\p"
	.string "Thankfully the Rest House is here is you\n"
	.string "or your Pokémon get tired.$"