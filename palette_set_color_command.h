#ifndef PALETTE_SET_COLOR_COMMAND_H
#define PALETTE_SET_COLOR_COMMAND_H

#include <wx/wx.h>
#include <wx/cmdproc.h>
#include "SA_document.h"
#include "SA_palette.h"

class PaletteSetColorCommand : public wxCommand
{
	public:
		typedef enum {
			PALETTE_SET_COLOR = 1,
			UNDO_PALETTE_SET_COLOR
		} PaletteSetColorOperation;

		PaletteSetColorCommand(const wxString& name,
				PaletteSetColorOperation op,
				SADocument* pDoc,
				SAPalette* pPalette,
				wxColor color,
				int8_t nIndex);
		~PaletteSetColorCommand();

		// Overrides
		virtual bool Do();
		virtual bool Undo();

	protected:
		bool DoOrUndo(PaletteSetColorOperation op);

	private:
		SAPalette* m_pPalette;
		SADocument* m_pDoc;
		PaletteSetColorOperation m_op;
		wxColor m_Color;
		int8_t m_nIndex;
};

#endif // PALETTE_SET_COLOR_COMMAND_H

