#pragma once

#include <wx/wx.h>
#include <wx/cmdproc.h>
#include "SA_document.h"

class SAFrame;

class SACreatePaletteCommand : public wxCommand
{
	public:
		typedef enum {
			CREATE_PALETTE = 1,
			UNDO_CREATE_PALETTE
		} CreatePaletteOperation;

		SACreatePaletteCommand(const wxString& name,
				CreatePaletteOperation op,
				SADocument* pDoc,
				SAFrame* pParentFrame);
		~SACreatePaletteCommand();

		// Overrides
		virtual bool Do();
		virtual bool Undo();

	protected:
		bool DoOrUndo(CreatePaletteOperation op);

	private:
		SADocument* m_pDoc;
		CreatePaletteOperation m_op;
		SAFrame* m_pParentFrame;
};
