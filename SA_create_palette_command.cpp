#include "SA_create_palette_command.h"
#include "SA_palette.h"

SACreatePaletteCommand::SACreatePaletteCommand(const wxString& name,
		CreatePaletteOperation op,
		SADocument* pDoc)
	: wxCommand(true, name)
{
	m_pDoc = pDoc;
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
			// add the new palette
			m_pDoc->GetPalettes().Append(new SAPalette());
			break;
		case UNDO_CREATE_PALETTE:
			SAPalette* pTemp = (SAPalette *) m_pDoc->GetPalettes().GetLast()->GetData();
			m_pDoc->GetPalettes().pop_back();
			delete pTemp;
			break;

	}

	m_pDoc->Modify(true);
	m_pDoc->UpdateAllViews();

	return true;
}

