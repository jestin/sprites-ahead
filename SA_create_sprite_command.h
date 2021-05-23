#pragma once

#include <wx/wx.h>
#include <wx/cmdproc.h>
#include "SA_document.h"

class SAFrame;

class SACreateSpriteCommand : public wxCommand
{
	public:
		typedef enum {
			CREATE_SPRITE = 1,
			UNDO_CREATE_SPRITE
		} CreateSpriteOperation;

		SACreateSpriteCommand(const wxString& name,
				CreateSpriteOperation op,
				SADocument* pDoc,
				SAFrame* pParentFrame);
		~SACreateSpriteCommand();

		// Overrides
		virtual bool Do();
		virtual bool Undo();

	protected:
		bool DoOrUndo(CreateSpriteOperation op);

	private:
		SADocument* m_pDoc;
		CreateSpriteOperation m_op;
		SAFrame* m_pParentFrame;
};
