Route3_MapScripts::
	.byte 0

Route3_EventScript_RouteSignErewood::
	msgbox Route3_Text_RouteSignErewood, MSGBOX_SIGN
	end

Route3_EventScript_RouteSignMoorden::
	msgbox Route3_Text_RouteSignMoorden, MSGBOX_SIGN
	end

Route3_Text_RouteSignErewood:
	.string "Route 3\p"
	.string "{UP_ARROW} Erewood Grove\n"
	.string "{DOWN_ARROW} Moorden Village$"

Route3_Text_RouteSignMoorden:
	.string "Route 3\p"
	.string "{DOWN_ARROW} Moorden Village\n"
	.string "{UP_ARROW} Erewood Grove$"

Speaker_Astor:
    .string "Astor$"

Route3_EventScript_Astor::
	trainerbattle_single TRAINER_ASTOR, Route3_Text_AstorIntro, Route3_Text_AstorDefeat
	setspeaker Speaker_Astor
	msgbox Route3_Text_AstorPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Nancy:
    .string "Nancy$"

Route3_EventScript_Nancy::
	trainerbattle_single TRAINER_NANCY, Route3_Text_NancyIntro, Route3_Text_NancyDefeat
	setspeaker Speaker_Nancy
	msgbox Route3_Text_NancyPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Opal:
    .string "Opal$"

Route3_EventScript_Opal::
	trainerbattle_single TRAINER_OPAL, Route3_Text_OpalIntro, Route3_Text_OpalDefeat
	setspeaker Speaker_Opal
	msgbox Route3_Text_OpalPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Kelan:
    .string "Kelan$"

Route3_EventScript_Kelan::
	trainerbattle_single TRAINER_KELAN, Route3_Text_KelanIntro, Route3_Text_KelanDefeat
	setspeaker Speaker_Kelan
	msgbox Route3_Text_KelanPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_BugCatcher:
    .string "Bug Catcher$"

Route3_EventScript_BugCatcher::
	lockall
	setspeaker Speaker_BugCatcher
	msgbox Route3_Text_BugCatcher, MSGBOX_NPC
	releaseall
	end

Route3_Text_BugCatcher:
	.string "Have you seen the Pokémon Venipede?\p"
	.string "I've always wanted one, and you can\n"
	.string "find them in Erewood Grove,\p"
	.string "but I'm too scared to go in...$"

Route3_EventScript_Elder::
	lockall
	setspeaker Speaker_Elder
	msgbox Route3_Text_Elder, MSGBOX_NPC
	releaseall
	end

Route3_Text_Elder:
	.string "Be careful in Erewood Grove up ahead.\p"
	.string "The dense forest is creepy, and it's\n"
	.string "very easy to get lost in there.$"
