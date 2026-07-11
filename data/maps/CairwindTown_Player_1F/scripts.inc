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
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_CAIRWIND_MOM, ContestHall_Movement_Heart
	waitmovement 0
	playse SE_PIN
	setspeaker Speaker_Mom
	msgbox CairwindTown_Player_1F_Text_MomSpeech, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAMERA, CairwindTown_Player_1F_Movement_FromMom
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_STORY, 2
	setflag FLAG_ROUTE7_PINE
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setflag FLAG_CAIRWIND_MOVE
	setflag FLAG_CAIRWIND_MART
	clearflag FLAG_HIDE_QUILSPRING_BERITH
	releaseall
	end

CairwindTown_Player_1F_EventScript_Mom::
	setspeaker Speaker_Mom
	call_if_eq VAR_STORY, 8, CairwindTown_Player_1F_EventScript_MomGetMap
	call_if_ge VAR_STORY, 9, CairwindTown_Player_1F_EventScript_MomPost
	msgbox CairwindTown_Player_1F_Text_Mom, MSGBOX_NPC
	end

CairwindTown_Player_1F_Movement_ToMom:
	walk_up
	walk_up
	walk_left
	step_end

CairwindTown_Player_1F_Movement_FromMom:
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

CairwindTown_Player_1F_EventScript_MomGetMap::
	lockall
	msgbox CairwindTown_Player_1F_Text_MomMap, MSGBOX_NPC
	closemessage
	giveitem ITEM_TOWN_MAP
	setspeaker Speaker_Mom
	msgbox CairwindTown_Player_1F_Text_MomSuitcase, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SUITCASE
	setspeaker Speaker_Mom
	msgbox CairwindTown_Player_1F_Text_MomGoodbye, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STORY, 9
	releaseall
	end

CairwindTown_Player_1F_Text_MomMap:
	.string "There you are {PLAYER}!\p"
	.string "Professor Pine came by the house and\n"
	.string "explained all that happened,\p"
	.string "it sounds like you have had quite\n"
	.string "the day today!\p"
	.string "And how exciting that you got your\n"
	.string "very first Pokémon!\p"
	.string "I always knew you would leave home one\n"
	.string "day, but just like every mother,\l"
	.string "I never thought it would be so soon.\p"
	.string "Before you leave, you'll need this!$"

CairwindTown_Player_1F_Text_MomSuitcase:
	.string "I also did your laundry and packed\n"
	.string "your suitcase for the trip!$"

CairwindTown_Player_1F_Text_MomGoodbye:
	.string "Have so much fun on your adventure\n"
	.string "and be safe! Know that you can always\l"
	.string "come home and rest.$"

CairwindTown_Player_1F_EventScript_MomPost::
	lockall
	setspeaker Speaker_Mom
	msgbox CairwindTown_Player_1F_Text_MomGoodLuck, MSGBOX_NPC
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

CairwindTown_Player_1F_Text_MomGoodLuck:
	.string "You look tired, you and your\n"
	.string "Pokémon should get some rest.$"
