ErewoodGrove_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ErewoodGrove_B1F_OnFrame
	.byte 0

ErewoodGrove_B1F_OnFrame:
	map_script_2 VAR_STORY, 13, ErewoodGrove_B1F_EventScript_MainSpeech
	.2byte 0

ErewoodGrove_B1F_EventScript_MainSpeech::
	lockall
	applymovement LOCALID_EREWOOD_B1F_JAMES, Common_Movement_FaceLeft
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	setspeaker Speaker_James
	msgbox ErewoodGrove_B1F_Text_JamesOkay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EREWOOD_B1F_JAMES, Common_Movement_FaceUp
	delay 8
	applymovement LOCALID_EREWOOD_B1F_JAMES, Common_Movement_FaceRight
	delay 8
	applymovement LOCALID_EREWOOD_B1F_JAMES, Common_Movement_FaceDown
	delay 8
	applymovement LOCALID_EREWOOD_B1F_JAMES, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_EREWOOD_B1F_JAMES, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	setspeaker Speaker_James
	msgbox ErewoodGrove_B1F_Text_JamesSystem, MSGBOX_DEFAULT
	closemessage	
	special HealPlayerParty
	applymovement LOCALID_EREWOOD_B1F_JAMES, Common_Movement_FaceDown
	setvar VAR_STORY, 14
	waitmovement 0
	releaseall
	end

ErewoodGrove_B1F_EventScript_James::
	lockall
	setspeaker Speaker_James
	msgbox ErewoodGrove_B1F_Text_James, MSGBOX_NPC
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

ErewoodGrove_B1F_Text_JamesOkay:
	.string "Are you okay?\p"
	.string "Well that was certainly something...\n"
	.string "Who were those people?\l"
	.string "And where are we?$"

ErewoodGrove_B1F_Text_JamesSystem:
	.string "It looks like there's a whole system\n"
	.string "within the tree hollow!\p"
	.string "Hopefully there's something around\n"
	.string "here that can help us get out of\l"
	.string "this place.\p"
	.string "My Pokémon are a little banged up\n"
	.string "after that battle, so I'm going to\l"
	.string "take a moment and rest up.\p"
	.string "I'll heal your Pokémon too!\n"
	.string "We'll join you in exploring in just\l"
	.string "a moment.$"


ErewoodGrove_B1F_Text_James:
	.string "I'll heal your Pokémon, good luck!$"

ErewoodGrove_B1F_EventScript_Hollow1::
	goto_if_unset FLAG_ITEM_ESCAPE_ROPE, ErewoodGrove_B1F_EventScript_NoRope
	lockall
	msgbox ErewoodGrove_B1F_Text_ClimbHollow, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, ErewoodGrove_B1F_EventScript_WarpHollow1
	releaseall
	end

ErewoodGrove_B1F_EventScript_NoRope::
	msgbox ErewoodGrove_B1F_Text_NoRope, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

ErewoodGrove_B1F_EventScript_WarpHollow1::
	warpsilent MAP_EREWOOD_GROVE, 24, 49
	releaseall
	end

ErewoodGrove_B1F_EventScript_Hollow2::
	lockall
	msgbox ErewoodGrove_B1F_Text_ClimbHollow, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, ErewoodGrove_B1F_EventScript_WarpHollow2
	releaseall
	end

ErewoodGrove_B1F_EventScript_WarpHollow2::
	warpsilent MAP_EREWOOD_GROVE, 57, 60
	releaseall
	end

ErewoodGrove_B1F_EventScript_Hollow3::
	lockall
	msgbox ErewoodGrove_B1F_Text_ClimbHollow, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, ErewoodGrove_B1F_EventScript_WarpHollow3
	releaseall
	end

ErewoodGrove_B1F_EventScript_WarpHollow3::
	warpsilent MAP_EREWOOD_GROVE, 53, 10
	releaseall
	end

ErewoodGrove_B1F_EventScript_Hollow4::
	lockall
	msgbox ErewoodGrove_B1F_Text_ClimbHollow, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, ErewoodGrove_B1F_EventScript_WarpHollow4
	releaseall
	end

ErewoodGrove_B1F_EventScript_WarpHollow4::
	warpsilent MAP_EREWOOD_GROVE, 10, 8
	releaseall
	end

ErewoodGrove_B1F_EventScript_Hollow5::
	lockall
	msgbox ErewoodGrove_B1F_Text_ClimbHollow, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, ErewoodGrove_B1F_EventScript_WarpHollow5
	releaseall
	end

ErewoodGrove_B1F_EventScript_WarpHollow5::
	warpsilent MAP_EREWOOD_GROVE, 30, 31
	releaseall
	end

ErewoodGrove_B1F_Text_NoRope:
	.string "There's light coming from the top of\n"
	.string "the tree trunk.$"

ErewoodGrove_B1F_Text_ClimbHollow:
	.string "There's light coming from the top of\n"
	.string "the tree trunk.\p"
	.string "Use the Escape Rope to climb out of\n"
	.string "the tree hollow?$"

ErewoodGrove_B1F_EventScript_EscapeRope::
	lockall
	finditem ITEM_ESCAPE_ROPE
	setobjectxyperm LOCALID_EREWOOD_B1F_JAMES, 13, 76
	removeobject LOCALID_EREWOOD_B1F_JAMES
	delay 1
	addobject LOCALID_EREWOOD_B1F_JAMES
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
	applymovement LOCALID_EREWOOD_B1F_JAMES, ErewoodGrove_B1F_Movement_JamesSecond
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	setspeaker Speaker_James
	msgbox ErewoodGrove_B1F_Text_JamesEscapeRope, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_EREWOOD_NICKNATE
	clearflag FLAG_HIDE_EREWOOD_JAMES
	setflag FLAG_ITEM_ESCAPE_ROPE
	special RemoveCameraObject
	warpsilent MAP_EREWOOD_GROVE, 24, 49
	releaseall
	end

ErewoodGrove_B1F_Movement_JamesSecond:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

ErewoodGrove_B1F_Text_JamesEscapeRope:
	.string "An Escape Rope, that's perfect!\n"
	.string "Now let's get out of here!$"


