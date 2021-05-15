#ifndef SA_CREATE_PALETEE_COMMAND_H
#define SA_CREATE_PALETEE_COMMAND_H

#include <wx/wx.h>
#include <wx/cmdproc.h>
#include "SA_document.h"

class SACreatePaletteCommand : public wxCommand
{
	public:
		typedef enum {
			CREATE_PALETTE = 1,
			UNDO_CREATE_PALETTE
		} CreatePaletteOperation;

		SACreatePaletteCommand(const wxString& name,
				CreatePaletteOperation op,
				SADocument* pDoc);
		~SACreatePaletteCommand();

		// Overrides
		virtual bool Do();
		virtual bool Undo();

	protected:
		bool DoOrUndo(CreatePaletteOperation op);

	private:
		SADocument* m_pDoc;
		CreatePaletteOperation m_op;
};

#endif // SA_CREATE_PALETEE_COMMAND_H

