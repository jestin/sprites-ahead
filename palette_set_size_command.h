#ifndef PALETTECOMMAND_H
#define PALETTECOMMAND_H

#include <wx/wx.h>
#include <wx/cmdproc.h>
#include "SA_document.h"
#include "SA_palette.h"

class PaletteSetSizeCommand : public wxCommand
{
	public:
		typedef enum {
			PALETTE_SET_SIZE = 1,
			UNDO_PALETTE_SET_SIZE
		} PaletteSetSizeOperation;

		PaletteSetSizeCommand(const wxString& name,
				PaletteSetSizeOperation op,
				SADocument* pDoc,
				SAPalette* pPalette,
				int8_t nColors);
		~PaletteSetSizeCommand();

		// Overrides
		virtual bool Do();
		virtual bool Undo();

	protected:
		bool DoOrUndo(PaletteSetSizeOperation op);


	private:
		SAPalette* m_pPalette;
		SADocument* m_pDoc;
		PaletteSetSizeOperation m_op;
		int8_t m_nColors;
};

#endif // PALETTECOMMAND_H

