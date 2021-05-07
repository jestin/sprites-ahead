#ifndef SET_ACTIVE_PALETTE_COMMAND_H
#define SET_ACTIVE_PALETTE_COMMAND_H

#include <wx/wx.h>
#include <wx/cmdproc.h>
#include "SA_document.h"

class SetActivePaletteCommand : public wxCommand
{
	public:
		typedef enum {
			SET_ACTIVE_PALETTE = 1,
			UNDO_SET_ACTIVE_PALETTE
		} SetActivePaletteOperation;

		SetActivePaletteCommand(const wxString& name,
				SetActivePaletteOperation op,
				SADocument* pDoc,
				int8_t nActivePalette);
		~SetActivePaletteCommand();

		// Overrides
		virtual bool Do();
		virtual bool Undo();

	protected:
		bool DoOrUndo(SetActivePaletteOperation op);

	private:
		SetActivePaletteOperation m_op;
		SADocument* m_pDoc;
		int8_t m_nActivePalette;
};

#endif // SET_ACTIVE_PALETTE_COMMAND_H

