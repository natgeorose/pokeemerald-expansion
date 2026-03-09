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