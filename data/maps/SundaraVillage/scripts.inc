SundaraVillage_MapScripts::
	.byte 0

SundaraVillage_EventScript_Gym::
	msgbox SundaraVillage_Text_Gym, MSGBOX_SIGN
	end

SundaraVillage_Text_Gym:
	.string "Sundara Village Gym\n"
	.string "Leader: Magnus\l"
	.string "Level Cap: 24$"

SundaraVillage_EventScript_TownSign::
	msgbox SundaraVillage_Text_TownSign, MSGBOX_SIGN
	end

SundaraVillage_Text_TownSign:
	.string "Sundara Village\n"
	.string "“The sunny mining town.”$"

SundaraVillage_EventScript_RockSmash::
	lockall
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SundaraVillage_Movement_WalkUp3
	waitmovement 0
	playse SE_M_ROCK_THROW
    	applymovement LOCALID_SUNDARA_ROCK, Movement_SmashRock
    	waitmovement 0
	removeobject LOCALID_SUNDARA_ROCK
	setflag FLAG_SUNDARA_ROCK
	applymovement LOCALID_MAGNUS_INSIDE, SundaraVillage_Movement_MagnusExit
	waitmovement 0
	removeobject LOCALID_MAGNUS_INSIDE
	playse SE_EXIT
	setflag FLAG_MAGNUS_OUTSIDE
	applymovement LOCALID_CAMERA, SundaraVillage_Movement_WalkDown3
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_STORY, 19
	releaseall
	end

SundaraVillage_Movement_MagnusExit:
    walk_fast_up
    walk_fast_up
    walk_fast_up
    walk_fast_up
    step_end

SundaraVillage_Movement_WalkUp3:
    walk_up
    walk_up
    walk_up
    step_end

SundaraVillage_Movement_WalkDown3:
    walk_down
    walk_down
    walk_down
    step_end


