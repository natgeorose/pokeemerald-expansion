Route6_MapScripts::
	.byte 0

Route6_EventScript_JumpRight::
	lockall
	applymovement LOCALID_PLAYER, Route6_Movement_JumpRight
	waitmovement 0
	releaseall
	end

Route6_Movement_JumpRight:
	jump_2_right
	walk_right
	step_end

Route6_EventScript_JumpLeft::
	lockall
	applymovement LOCALID_PLAYER, Route6_Movement_JumpLeft
	waitmovement 0
	releaseall
	end

Route6_Movement_JumpLeft:
	jump_2_left
	walk_left
	step_end

Speaker_Kendall:
    .string "Kendall$"

Route6_EventScript_Kendall::
	trainerbattle_single TRAINER_KENDALL, Route6_Text_KendallIntro, Route6_Text_KendallDefeat
	setspeaker Speaker_Kendall
	msgbox Route6_Text_KendallPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Jordy:
    .string "Jordy$"

Route6_EventScript_Jordy::
	trainerbattle_single TRAINER_JORDY, Route6_Text_JordyIntro, Route6_Text_JordyDefeat
	setspeaker Speaker_Jordy
	msgbox Route6_Text_JordyPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Noah:
    .string "Noah$"

Route6_EventScript_Noah::
	trainerbattle_single TRAINER_NOAH, Route6_Text_NoahIntro, Route6_Text_NoahDefeat
	setspeaker Speaker_Noah
	msgbox Route6_Text_NoahPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Winston:
    .string "Winston$"

Route6_EventScript_Winston::
	trainerbattle_single TRAINER_WINSTON, Route6_Text_WinstonIntro, Route6_Text_WinstonDefeat
	setspeaker Speaker_Winston
	msgbox Route6_Text_WinstonPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Simon:
    .string "Simon$"

Route6_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route6_Text_SimonIntro, Route6_Text_SimonDefeat
	setspeaker Speaker_Simon
	msgbox Route6_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Gloria:
    .string "Gloria$"

Route6_EventScript_Gloria::
	trainerbattle_single TRAINER_GLORIA, Route6_Text_GloriaIntro, Route6_Text_GloriaDefeat
	setspeaker Speaker_Gloria
	msgbox Route6_Text_GloriaPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Hudson:
    .string "Hudson$"

Route6_EventScript_Hudson::
	trainerbattle_single TRAINER_HUDSON, Route6_Text_HudsonIntro, Route6_Text_HudsonDefeat
	setspeaker Speaker_Hudson
	msgbox Route6_Text_HudsonPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Brody:
    .string "Brody$"

Route6_EventScript_Brody::
	trainerbattle_single TRAINER_BRODY, Route6_Text_BrodyIntro, Route6_Text_BrodyDefeat
	setspeaker Speaker_Brody
	msgbox Route6_Text_BrodyPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Marcus:
    .string "Marcus$"

Route6_EventScript_Marcus::
	trainerbattle_single TRAINER_MARCUS, Route6_Text_MarcusIntro, Route6_Text_MarcusDefeat
	setspeaker Speaker_Marcus
	msgbox Route6_Text_MarcusPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Autumn:
    .string "Autumn$"

Route6_EventScript_Autumn::
	trainerbattle_single TRAINER_AUTUMN, Route6_Text_AutumnIntro, Route6_Text_AutumnDefeat
	setspeaker Speaker_Autumn
	msgbox Route6_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_RouteSign::
	msgbox Route6_Text_RouteSign, MSGBOX_SIGN
	end

Route6_Text_RouteSign:
	.string "Route 6\n"
	.string "{DOWN_ARROW} Route 5\l"
	.string "{UP_ARROW} Sundara Village$"
