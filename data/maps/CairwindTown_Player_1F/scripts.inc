CairwindTown_Player_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CairwindTown_Player_1F_OnFrame
	.byte 0

CairwindTown_Player_1F_OnFrame:
	map_script_2 VAR_STORY, 1, CairwindTown_Player_1F_EventScript_MomSpeech
	.2byte 0

Speaker_Mom:
    .string "Mom$"

CairwindTown_Player_1F_EventScript_MomSpeech::
	lockall
	delay 15
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, CairwindTown_Player_1F_Movement_ToMom
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_CAIRWIND_MOM, ContestHall_Movement_Heart
	waitmovement 0
	setspeaker Speaker_Mom
	msgbox CairwindTown_Player_1F_Text_MomSpeech, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAMERA, CairwindTown_Player_1F_Movement_FromMom
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_STORY, 2
	releaseall
	end

CairwindTown_Player_1F_EventScript_Mom::
	setspeaker Speaker_Mom
	msgbox CairwindTown_Player_1F_Text_Mom, MSGBOX_NPC
	end

CairwindTown_Player_1F_Movement_ToMom:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

CairwindTown_Player_1F_Movement_FromMom:
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

CairwindTown_Player_1F_Text_MomSpeech:
	.string "Hi honey, how was the lesson today?\p"
	.string "I heard that Professor Pine is going\n"
	.string "to be in town today, that's exciting!\p"
	.string "Oh, James was looking for you,\n"
	.string "he said it was something urgent.\p"
	.string "Whatever it is, have fun and be safe!$"

CairwindTown_Player_1F_Text_Mom:
	.string "Hope you have fun today!\p"
	.string "I'll be home all day, so let\n"
	.string "me know if you need anything!$"

