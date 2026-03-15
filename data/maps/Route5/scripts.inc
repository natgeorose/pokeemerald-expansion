Route5_MapScripts::
	.byte 0

Route5_EventScript_RouteSign::
	msgbox Route5_Text_RouteSign, MSGBOX_SIGN
	end

Route5_Text_RouteSign:
	.string "Route 4\n"
	.string "{DOWN_ARROW} Erewood Grove\p"
	.string "{UP_ARROW} Route 6\n"
	.string "{RIGHT_ARROW} Fellhaven Town$"

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



