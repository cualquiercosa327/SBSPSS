
/*=========================================================================

	psjump.cpp

	Author:		PKG
	Created: 
	Project:	Spongebob
	Purpose: 

	Copyright (c) 2001 Climax Development Ltd

===========================================================================*/


/*----------------------------------------------------------------------
	Includes
	-------- */

#include "player\psjump.h"

#ifndef __PLAYER_PLAYER_H__
#include "player\player.h"
#endif

#ifndef __PAD_PADS_H__
#include "pad\pads.h"
#endif


/*	Std Lib
	------- */

/*	Data
	---- */

#ifndef	__ANIM_PLAYER_ANIM_HEADER__
#include <player_anim.h>
#endif


/*----------------------------------------------------------------------
	Tyepdefs && Defines
	------------------- */

/*----------------------------------------------------------------------
	Structure defintions
	-------------------- */

/*----------------------------------------------------------------------
	Function Prototypes
	------------------- */

/*----------------------------------------------------------------------
	Vars
	---- */

/*----------------------------------------------------------------------
	Function:
	Purpose:
	Params:
	Returns:
  ---------------------------------------------------------------------- */
void CPlayerStateJump::enter(CPlayer *_player)
{
	const PlayerMetrics	*metrics;

	metrics=getPlayerMetrics(_player);

	setAnimNo(_player,ANIM_PLAYER_ANIM_JUMPSTART);
	m_jumpFrames=0;
	DVECTOR	move=getMoveVelocity(_player);
	move.vy=-metrics->m_metric[PM__JUMP_VELOCITY]<<CPlayer::VELOCITY_SHIFT;
	setMoveVelocity(_player,&move);
}


/*----------------------------------------------------------------------
	Function:
	Purpose:
	Params:
	Returns:
  ---------------------------------------------------------------------- */
void CPlayerStateJump::think(CPlayer *_player)
{
	const PlayerMetrics	*metrics;
	int					control;

	metrics=getPlayerMetrics(_player);
	control=getPadInput(_player);

	if(m_jumpFrames<=metrics->m_metric[PM__MAX_JUMP_FRAMES]&&control&CPadConfig::getButton(CPadConfig::PAD_CFG_JUMP))
	{
		m_jumpFrames++;
	}
	else
	{
		DVECTOR	move;
		move=getMoveVelocity(_player);
		if(move.vy>=0)
		{
			setState(_player,STATE_FALL);
		}
		else
		{
			move.vy+=metrics->m_metric[PM__GRAVITY_VALUE];
		}
		setMoveVelocity(_player,&move);
	}

	if(control&CPadConfig::getButton(CPadConfig::PAD_CFG_LEFT))
	{
		moveLeft(_player);
	}
	else if(control&CPadConfig::getButton(CPadConfig::PAD_CFG_RIGHT))
	{
		moveRight(_player);
	}
	else
	{
		slowdown(_player);
	}
}


/*===========================================================================
 end */
