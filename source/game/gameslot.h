/*=========================================================================

	gameslot.h

	Author:		PKG
	Created:
	Project:	Spongebob
	Purpose:

	Copyright (c) 2001 Climax Development Ltd

===========================================================================*/

#ifndef	__GAME_GAMESLOT_H__
#define	__GAME_GAMESLOT_H__

/*----------------------------------------------------------------------
	Includes
	-------- */

#ifndef __SHOP_SHOP_H__
#include "shop\shop.h"
#endif

// Just for ASSERT()..
#ifndef	__SYSTEM_DBG_H__
#include "system\dbg.h"
#endif


/*	Std Lib
	------- */

/*----------------------------------------------------------------------
	Tyepdefs && Defines
	------------------- */

/*----------------------------------------------------------------------
	Structure defintions
	-------------------- */

class CGameSlotManager
{
public:
	enum
	{
		INITIAL_LIVES=4,
		INITIAL_CONTINUES=3,
		
		NUM_GAME_SLOTS=4,

		NUM_CHAPTERS=5,
		NUM_LEVELS_WITH_SPATULAS=4,
	};
	

	typedef struct
	{
		unsigned char	m_isInUse;
		unsigned char	m_lives;
		unsigned char	m_continues;
		unsigned char	m_maxLevelCompleted;
		unsigned char	m_spatulaCollectedFlags[NUM_CHAPTERS*NUM_LEVELS_WITH_SPATULAS][16];			// Enuf space for 128 spats per level
		unsigned char	m_kelpTokenCollectedFlags[NUM_CHAPTERS][16];								// Same again..
		unsigned char	m_kelpTokensHeld;
		unsigned char	m_partyItemsHeld[CShopScene::NUM_SHOP_ITEM_IDS];

		// Spat functions..
		int				getSpatulaCollectedCount(unsigned int _chapter,unsigned int _level)
		{
			ASSERT(_chapter<=NUM_CHAPTERS);
			ASSERT(_level<=NUM_LEVELS_WITH_SPATULAS);
			int		i,j,count;
			count=0;
			for(i=0;i<8;i++)
			{
				unsigned char	flags=m_spatulaCollectedFlags[(_chapter*NUM_LEVELS_WITH_SPATULAS)+_level][i];
				for(j=0;j<8;j++)
				{
					if(flags&1)count++;
					flags>>=1;
				}
			}
			return count;
		}
		void			collectSpatula(unsigned int _chapter,unsigned int _level,unsigned int _spat)
		{
			ASSERT(_chapter<=NUM_CHAPTERS);
			ASSERT(_level<=NUM_LEVELS_WITH_SPATULAS);
			ASSERT(_spat<=128);
			m_spatulaCollectedFlags[(_chapter*NUM_LEVELS_WITH_SPATULAS)+_level][_spat>>3]|=1<<(_spat&7);
		}
		int				isSpatulaUncollected(unsigned int _chapter,unsigned int _level,unsigned int _spat)
		{
			ASSERT(_chapter<=NUM_CHAPTERS);
			ASSERT(_level<=NUM_LEVELS_WITH_SPATULAS);
			ASSERT(_spat<=128);
			return (m_spatulaCollectedFlags[(_chapter*NUM_LEVELS_WITH_SPATULAS)+_level][_spat>>3]>>(_spat&7))&1?false:true;
		}

		// Kelp Token functions..
		int				getKelpTokenCollectedCount(unsigned int _chapter,unsigned int _level)
		{
			ASSERT(_chapter<=NUM_CHAPTERS);
			ASSERT(_level==NUM_LEVELS_WITH_SPATULAS);
			int		i,j,count;
			count=0;
			for(i=0;i<8;i++)
			{
				unsigned char	flags=m_kelpTokenCollectedFlags[_chapter][i];
				for(j=0;j<8;j++)
				{
					if(flags&1)count++;
					flags>>=1;
				}
			}
			return count;
		}
		void			collectKelpToken(unsigned int _chapter,unsigned int _level,unsigned int _token)
		{
			ASSERT(_chapter<=NUM_CHAPTERS);
			ASSERT(_level==NUM_LEVELS_WITH_SPATULAS);
			ASSERT(_token<=128);
			m_kelpTokenCollectedFlags[_chapter][_token>>3]|=1<<(_token&7);
		}
		int				isKelpTokenUncollected(unsigned int _chapter,unsigned int _level,unsigned int _token)
		{
			ASSERT(_chapter<=NUM_CHAPTERS);
			ASSERT(_level==NUM_LEVELS_WITH_SPATULAS);
			ASSERT(_token<=128);
			return (m_kelpTokenCollectedFlags[_chapter][_token>>3]>>(_token&7))&1?false:true;
		}

		// Shop
		int				getNumberOfKelpTokensHeld()
		{
			return m_kelpTokensHeld;
		}
		void			useKelpTokens(int _count)
		{
			ASSERT(((int)m_kelpTokensHeld-_count)>=0);
			m_kelpTokensHeld-=_count;
		}
		int				isPartyItemHeld(int _itemNumber)
		{
			return m_partyItemsHeld[_itemNumber];
		}
		void			buyPartyItem(int _itemNumber)
		{
			ASSERT(!m_partyItemsHeld[_itemNumber]);
			m_partyItemsHeld[_itemNumber]=true;
		}
	} GameSlot;

	static void			init();

	static void			setActiveSlot(unsigned int _slot);
	static GameSlot		*getSlotData();
	static void			setSlotData(GameSlot *_data);

	static void			eraseGameSlot(unsigned int _slot);
	static void			copyGameSlot(unsigned int _src,unsigned int _dest);


private:
	static GameSlot		s_gameSlots[NUM_GAME_SLOTS];
	static GameSlot		*s_currentGameSlot;

	// These allow the CSaveLoadDatabase total access to the game slots
	static void			setSlotData(int _slot,GameSlot *_data);
	static GameSlot		getSlotData(int _slot);
	friend class CSaveLoadDatabase;


};


/*----------------------------------------------------------------------
	Globals
	------- */

/*----------------------------------------------------------------------
	Functions
	--------- */

/*---------------------------------------------------------------------- */

#endif	/* __GAME_GAMESLOT_H__ */

/*===========================================================================
 end */
