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


