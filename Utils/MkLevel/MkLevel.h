/*************************/
/*** Base Level Holder ***/
/*************************/

#ifndef	__MKLEVEL_HEADER__
#define	__MKLEVEL_HEADER__

#include	<vector>
#include	<List.h>
#include	<FaceStore.h>
#include	"IniClass.h"

// Map Editor header files
#include	"..\mapedit\LayerDef.h"
#include	"..\mapedit\ExportHdr.h"

using namespace std;

//***************************************************************************
/*
struct	sMkLevelTex
{
		int		Set;
		int		XOfs,YOfs;
//		u8		*RGB;
		int		Flags;
//		int		RChk,GChk,BChk;
		int		TexID;

bool	operator ==(sMkLevelTex const &v1)
		{
		if (Set!=v1.Set) return(false);
		if (XOfs!=v1.XOfs) return(false);
		if (YOfs!=v1.YOfs) return(false);
		if (Flags!=v1.Flags) return(false);
		return(true);
		}
};
*/

struct	sMkLevelTex
{
//		int		Set;
//		int		XOfs,YOfs;
		int		Tile;
		int		Flags;
		int		TexID;

bool	operator ==(sMkLevelTex const &v1)
		{
//		if (Set!=v1.Set) return(false);
//		if (XOfs!=v1.XOfs) return(false);
//		if (YOfs!=v1.YOfs) return(false);
		if (Tile!=v1.Tile) return(false);
		if (Flags!=v1.Flags) return(false);
		return(true);
		}
};

//***************************************************************************
struct	sMkLevelModel
{
		GString	Name;
		int		TriStart;
		int		TriCount;

bool	operator ==(sMkLevelModel const &v1)		{return(Name==v1.Name);}
};

//***************************************************************************
struct	sInfItem
{
	GString	Name;
	int		Val;
bool	operator ==(sInfItem const &v1)		{return(Name==v1.Name);}

};

//***************************************************************************
struct	sMkLevelLayerThing;
class	CMkLevelLayer;
class	CMkLevel
{
public:
		CMkLevel();
		~CMkLevel();

		void			SetAppDir(const char *Path);
		void			Init(const char *InFilename,const char *OutFilename,const char *IncDir,int TPBase,int TPW,int TPH,int PakW,int PakH);

		void			LoadModels();
		int				AddModel(GString &Filename);
		int				AddModel(const char *Name,int TriStart,int TriCount);

		void			Load();

		void			Process();
		int				AddTile3d(sExpLayerTile &Tile)			{return(Tile3dList.Add(Tile));}
		int				AddTile2d(sExpLayerTile &Tile)			{return(Tile2dList.Add(Tile));}

		void			AddInfItem(const char *Name,int Val);
		void			Write();

		int				Create2dTex(int Tile,int Flags);
		int				Create3dTile(sExpLayerTile &ThisTile);
//		int				FindRGBMatch(sMkLevelTex &ThisTex);
//		bool			IsRGBSame(const sMkLevelTex &Tile0,const sMkLevelTex &Tile1);
		void			MakeTexName(sExpTile &SrcTile,int Flags,GString &OutStr);
		int				BuildTileTex(sExpTile &SrcTile,int Flags);

		char			*GetConfigStr(const char *Grp,const char *Key)	{return(Config.GetStr(Grp,Key));}
		int				GetConfigInt(const char *Grp,const char *Key)	{return(Config.GetInt(Grp,Key));}
		CIni			&GetConfig()									{return(Config);}
		CTexGrab		&GetTexGrab()									{return(TexGrab);}

		void			SetStart(int X,int Y)				{LevelHdr.PlayerStartX=X; LevelHdr.PlayerStartY=Y;}

		void			GetPakWH(int &W,int &H)				{W=PakW; H=PakH;}
protected:	
		void			BuildModel(CScene &ThisScene,GString &RootPath,int Node);
		CMkLevelLayer	*FindLayer(int Type,int SubType);
		void			LoadStrList(CList<GString> &List,char *TexPtr,int Count);

		void			LoadTiles(sExpFileHdr *FileHdr);
		void			LoadLayers(sExpFileHdr *FileHdr);
		void			LoadLayer(sExpLayerHdr *LayerHdr);

		void			PreProcessLayers();
		void			ProcessTileBanks();
		void			PreProcessTileBank2d();
		void			ProcessTileBank2d();
		void			PreProcessTileBank3d();
		void			ProcessTileBank3d();
		void			ProcessLayers();
		void            SetUpTileUV(sTile2d &Out, sTexOutInfo &Info);

		void			ProcessModels();

		void			WriteLevel();
		void			WriteLayers();
		int				WriteLayer(int Type,int SubType,bool Warn=false);
		int				WriteThings(int Type,bool Warn=false);
		int				WriteModelList();
		int				WriteTriList();
		int				WriteQuadList();
		int				WriteVtxList();
		void			WriteTileBank();
		void			CalcModelBBox(sMkLevelModel &ThisModel,sBBox &BBox);
		void            BuildTiles();

		void			WriteIncFile();

		void			ReportLayers();
		char			*GetLayerName(int Type,int SubType);

		void			ExpTri2Face(sExpTri &In,CFace &Out,bool ImportTex=true);

		FILE					*File;
		GString					InFilename,InPath,LevelName,LevelFullName;
		GString					OutName,OutIncName;
		GString					AppDir;

		int						TileW,TileH;
		CIni					Config;
		
		CList<sExpTri>			InTriList;
		CList<sExpTile>			InTileList;
		CList<GString>			InSetNameList;
		CList<GString>			InTexNameList;
		CList<GString>			UsedSetNameList;
		CList<GString>			UsedTexNameList;

		CFaceStore				OutFaceList;
		CList<sTile2d>			OutTile2dList;
		CList<sTile3d>			OutTile3dList;

		CList<sExpLayerTile>	Tile2dList;
		CList<sExpLayerTile>	Tile3dList;
		CList<sMkLevelTex>		Tex2dList;
		CTexGrab				TexGrab;
		CList<Frame>			BmpList;

		vector<CMkLevelLayer*>	LayerList;

		CList<sMkLevelModel>	ModelList;
		CFaceStore				ModelFaceList;

		sLevelHdr				LevelHdr;
		sExpTri					FlatFace[2];

		CList<sInfItem>			InfList;

		int						PakW,PakH;

};

//***************************************************************************
#endif
