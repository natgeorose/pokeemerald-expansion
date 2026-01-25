QuilspringTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, QuilspringTown_Gym_OnLoad
	.byte 0

QuilspringTown_Gym_OnLoad:
	call_if_set FLAG_SYS_QUILSPRING_PUZZLE_COMPLETED, QuilspringTown_Gym_EventScript_ShowSecretDoor
	end

QuilspringTown_Gym_EventScript_ShowSecretDoor::
	setmetatile 11, 19, METATILE_Indoor_NonDoor, FALSE
	return

Speaker_Clara:
    .string "Clara$"

QuilspringTown_Gym_EventScript_Clara::
	trainerbattle_single TRAINER_CLARA, QuilspringTown_Gym_Text_ClaraIntro, QuilspringTown_Gym_Text_ClaraDefeat
	setspeaker Speaker_Clara
	msgbox QuilspringTown_Gym_Text_ClaraPostBattle, MSGBOX_AUTOCLOSE
	end

Speaker_Annika:
    .string "Annika$"

QuilspringTown_Gym_EventScript_Annika::
	trainerbattle_single TRAINER_ANNIKA, QuilspringTown_Gym_Text_AnnikaIntro, QuilspringTown_Gym_Text_AnnikaDefeat
	setspeaker Speaker_Annika
	msgbox QuilspringTown_Gym_Text_AnnikaPostBattle, MSGBOX_AUTOCLOSE
	end

QuilspringTown_Gym_EventScript_FoundSwitch::
	call_if_defeated TRAINER_CLARA, QuilspringTown_Gym_EventScript_CheckSwitch
	end

QuilspringTown_Gym_EventScript_CheckSwitch::
	call_if_defeated TRAINER_ANNIKA, QuilspringTown_Gym_EventScript_ActivateSwitch
	end

QuilspringTown_Gym_EventScript_ActivateSwitch::
	call_if_unset FLAG_SYS_QUILSPRING_PUZZLE_COMPLETED, QuilspringTown_Gym_EventScript_PressSwitch
	lockall
	msgbox QuilspringTown_Gym_Text_AlreadyPressed, MSGBOX_AUTOCLOSE
	releaseall
	end

QuilspringTown_Gym_EventScript_PressSwitch::
	lockall
	msgbox QuilspringTown_Gym_Text_YouFoundIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, QuilspringTown_Gym_EventScript_YouPressedIt
	msgbox QuilspringTown_Gym_Text_BookBack, MSGBOX_AUTOCLOSE	
	releaseall
	end

QuilspringTown_Gym_EventScript_YouPressedIt::
	msgbox QuilspringTown_Gym_Text_PressSwitch, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	delay 40
	setmetatile 11, 19, METATILE_Indoor_NonDoor, FALSE
	special DrawWholeMapView
	setflag FLAG_SYS_QUILSPRING_PUZZLE_COMPLETED
	releaseall
	end

QuilspringTown_Gym_Text_AlreadyPressed:
	.string "The switch has already been pressed.$"

QuilspringTown_Gym_Text_YouFoundIt:
	.string "{PLAYER} picked up the book and looked\n"
	.string "at the cover:\p"
	.string "'A Court of Ferrothorns and Roserades'\n"
	.string "by Sarah J. Maushold\p"
	.string "Do you want to open the book?$"

QuilspringTown_Gym_Text_BookBack:
	.string "{PLAYER} put the book back on the shelf.$"

QuilspringTown_Gym_Text_PressSwitch:
	.string "There is a hidden switch inside!\n"
	.string "{PLAYER} pressed the switch.$"

