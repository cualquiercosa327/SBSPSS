/******************/
/*** Layer Item ***/
/******************/

#ifndef	__LAYER_ITEM_HEADER__
#define	__LAYER_ITEM_HEADER__

#include	"LayerThing.h"
#include	"Layer.h"
#include	"MapEdit.h"
#include	"GUIToolbar.h"
#include	"Elem.h"

/*****************************************************************************/
class	CLayerItem : public CLayerThing
{
public:
		CLayerItem(sLayerDef &Def);
		CLayerItem(CFile *File,int Version)	{Load(File,Version);}

		void			InitSubView(CCore *Core);

		void			GUIInit(CCore *Core);
		void			GUIKill(CCore *Core);
		void			GUIUpdate(CCore *Core);
		void			GUIChanged(CCore *Core);

		void			Load(CFile *File,int Version);
		void			Save(CFile *File);
		void			LoadThingScript(const char *Filename);

		void			Export(CCore *Core,CExport &Exp);

protected:
		CGUIToolBar			GUIToolBar;

};

/*****************************************************************************/
#endif
