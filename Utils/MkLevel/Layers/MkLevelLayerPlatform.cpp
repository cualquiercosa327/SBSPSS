/**********************/
/*** Layer Platform ***/
/**********************/

#include	<Davelib.h>
#include	<List2d.h>

//#include	"MkLevel.h"
#include	"MkLevelLayerPlatform.h"


/*****************************************************************************/
/*****************************************************************************/
/*** Pre-Process *************************************************************/
/*****************************************************************************/
/*****************************************************************************/
void	CMkLevelLayerPlatform::PreProcess(CMkLevel *Core)
{
int		i,ListSize;
		ProcessList(Core);

		ListSize=ThingList.size();
		RemapTable.resize(ListSize);
		for (i=0; i<ListSize; i++)
		{
			sMkLevelLayerThing	&ThisThing=ThingList[i];
			RemapTable[i]=Core->AddModel(ThisThing.Name,ThisThing.Data.Platform.PlatformTriStart,ThisThing.Data.Platform.PlatformTriCount);
		}

		printf("%i Platforms\n",ThingList.size());
}

/*****************************************************************************/
/*****************************************************************************/
/*** Process *****************************************************************/
/*****************************************************************************/
/*****************************************************************************/
void	CMkLevelLayerPlatform::Process(CMkLevel *Core)
{
}

/*****************************************************************************/
/*****************************************************************************/
/** Write ********************************************************************/
/*****************************************************************************/
/*****************************************************************************/
int		CMkLevelLayerPlatform::Write(CMkLevel *Core,FILE *File,const char *LayerName)
{
int			ThisPos=ftell(File);
sThingHdr	Hdr;
int			i,ListSize=ThingList.size();
		
		Hdr.Count=ListSize;
		fwrite(&Hdr,sizeof(sThingHdr),1,File);

		for (i=0; i<ListSize; i++)
		{
			sMkLevelLayerThing	&ThisThing=ThingList[i];
			int					p,PointCount=ThisThing.XY.size();
			sThingPlatform			OutThing;

			OutThing.Type=ThisThing.Type;
			OutThing.Speed=ThisThing.Data.Platform.PlatformSpeed;
			OutThing.TurnRate=ThisThing.Data.Platform.PlatformTurnRate;
			OutThing.Flags=0;
			if (ThisThing.Data.Platform.PlatformCollisionFlag) OutThing.Flags|=THING_FLAG_COLLISION;
			if (ThisThing.Data.Flip & PC_TILE_FLAG_MIRROR_X) OutThing.Flags|=THING_FLAG_MIRRORX;
			if (ThisThing.Data.Flip & PC_TILE_FLAG_MIRROR_Y) OutThing.Flags|=THING_FLAG_MIRRORY;

			OutThing.PointCount=PointCount;
			OutThing.Gfx=RemapTable[i];
			OutThing.Param0=ThisThing.Data.Platform.PlatformParam0;
			fwrite(&OutThing,sizeof(sThingPlatform),1,File);

			for (p=0;p<PointCount;p++)
			{
				sThingPoint	Pnt;
				Pnt.X=ThisThing.XY[p].x;
				Pnt.Y=ThisThing.XY[p].y;
				fwrite(&Pnt,sizeof(sThingPoint),1,File);
			}
		}

		Size=ftell(File)-ThisPos;
		return(ThisPos);
}

/*****************************************************************************/
