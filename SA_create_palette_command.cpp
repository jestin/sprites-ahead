#include "SA_create_palette_command.h"
#include "SA_palette.h"
#include "SA_frame.h"
#include "SA_palette_frame.h"

SACreatePaletteCommand::SACreatePaletteCommand(const wxString& name,
		CreatePaletteOperation op,
		SADocument* pDoc,
		SAFrame* pParentFrame)
	: wxCommand(true, name)
{
	m_pDoc = pDoc;
	m_pParentFrame = pParentFrame;
	m_op = op;
}

SACreatePaletteCommand::~SACreatePaletteCommand()
{
}

bool SACreatePaletteCommand::Do()
{
	return DoOrUndo(m_op);
}

bool SACreatePaletteCommand::Undo()
{
	return DoOrUndo(m_op);
}

bool SACreatePaletteCommand::DoOrUndo(CreatePaletteOperation op)
{
	wxASSERT(m_pDoc != NULL);

	switch(op)
	{
		case CREATE_PALETTE:
			{
				// add the new palette
				m_pDoc->GetPalettes().Append(new SAPalette());

				// create frame
				SAPaletteFrame *f = new SAPaletteFrame(m_pParentFrame, "Palette");
				f->Show();
				break;
			}

		case UNDO_CREATE_PALETTE:
			{
				wxObjectListNode* node = m_pDoc->GetPalettes().GetLast();
				if(node == NULL) break;
				SAPalette* pTemp = (SAPalette *) node->GetData();
				m_pDoc->GetPalettes().pop_back();
				delete pTemp;
				break;
			}
	}

	m_pDoc->Modify(true);
	m_pDoc->UpdateAllViews();

	return true;
}

